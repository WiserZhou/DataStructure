#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXS 10
#define MINS 3
#define MAXB 5
#define MAXTable 500009

typedef char ElementType[10 + 1];

typedef struct FileEntry
{
    int words;
    struct FileEntry *Next;
} WList;

typedef struct WordEntry
{
    int FileNo;
    struct WordEntry *Next;
} FList;

struct HashEntry
{
    ElementType Element;
    int FileNo;
    FList *InvIndex;
};

typedef struct HashTbl
{
    int TableSize;
    struct HashEntry *TheCells;
} HashTable;

HashTable *Table_Init(int TableSize)
{
    HashTable *H = (HashTable *)malloc(sizeof(HashTable));
    H->TableSize = TableSize;
    H->TheCells = (struct HashEntry *)malloc(sizeof(struct HashEntry) * H->TableSize);
    while (TableSize)
    {
        H->TheCells[--TableSize].FileNo = 0;
        H->TheCells[TableSize].InvIndex = NULL;
    }
    return H;
}

WList *FileIndex_Init(int Size)
{
    WList *F = (WList *)malloc(sizeof(WList) * Size);
    while (Size)
    {
        F[--Size].words = 0;
        F[Size].Next = NULL;
    }
    return F;
}

int GetWord(ElementType Word)
{
    char c;
    int p = 0;
    scanf("%c", &c);
    while (!isalpha(c) && (c != '#'))
        scanf("%c", &c);
    if (c == '#')
        return 0;
    while (isalpha(c) && (p < MAXS))
    {
        Word[p++] = tolower(c);
        scanf("%c", &c);
    }
    while (isalpha(c))
        scanf("%c", &c);
    if (p < MINS)
        return GetWord(Word);
    else
    {
        Word[p] = '\0';
        return 1;
    }
}

int Hash(char *key, int p)
{
    unsigned int h = 0;
    while (*key != '\0')
        h = (h << MAXB) + (*key++ - 'a');
    return h % p;
}

int Find(ElementType key, HashTable *H)
{
    int pos = Hash(key, H->TableSize);
    while (H->TheCells[pos].FileNo && strcmp(H->TheCells[pos].Element, key))
    {
        pos++;
        if (pos == H->TableSize)
            pos -= H->TableSize;
    }
    return pos;
}

int InsertAndIndex(int FileNo, ElementType key, HashTable *H)
{
    FList *F;
    int pos = Find(key, H);
    if (H->TheCells[pos].FileNo != FileNo)
    {
        if (!H->TheCells[pos].FileNo)
            strcpy(H->TheCells[pos].Element, key);
        H->TheCells[pos].FileNo = FileNo;
        F = (FList *)malloc(sizeof(FList));
        F->FileNo = FileNo;
        F->Next = H->TheCells[pos].InvIndex;
        H->TheCells[pos].InvIndex = F;
        return pos;
    }
    else
        return -1;
}

void FileIndex(WList *File, int FileNo, int pos)
{
    WList *W;
    if (pos < 0)
        return;
    W = (WList *)malloc(sizeof(WList));
    W->words = pos;
    W->Next = File[FileNo - 1].Next;
    File[FileNo - 1].Next = W;
    File[FileNo - 1].words++;
}

double work(WList *File, int F1, int F2, HashTable *H)
{
    int temp;
    WList *W;
    FList *F;
    if (File[F1 - 1].words > File[F2 - 1].words)
    {
        temp = F1;
        F1 = F2;
        F2 = temp;
    }
    temp = 0;
    W = File[F1 - 1].Next;
    while (W)
    {
        F = H->TheCells[W->words].InvIndex;
        while (F)
        {
            if (F->FileNo == F2)
                break;
            F = F->Next;
        }
        if (F)
            temp++;
        W = W->Next;
    }
    return ((double)(temp * 100) / (double)(File[F1 - 1].words + File[F2 - 1].words - temp));
}

int main()
{
    int n, m, f1, f2;
    ElementType word;
    HashTable *H;
    WList *File;
    scanf("%d", &n);
    File = FileIndex_Init(n);
    H = Table_Init(MAXTable);
    for (int i = 0; i < n; i++)
        while (GetWord(word))
            FileIndex(File, i + 1, InsertAndIndex(i + 1, word, H));
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &f1, &f2);
        printf("%.1f%c\n", work(File, f1, f2, H), '%');
    }
    return 0;
}
