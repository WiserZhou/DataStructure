

#include <iostream>
#include <cstdlib>

struct BiTNode
{
    char data;
    BiTNode *Lchild;
    BiTNode *Rchild;
};

typedef BiTNode *BiTree;

int Search(char arr[], char target, int start, int end)
{
    for (int i = start; i <= end; i++)
        if (arr[i] == target)
            return i; // �ҵ�Ŀ��Ԫ�ص��±�
    return -1;
}

void CrtBT(BiTree &T, char pre[], char ino[], int ps, int is, int n)
// ps����pre�Ŀ�ʼ��ţ�is����ino�Ŀ�ʼ�±�
{
    if (n == 0) // ��ʾΪ����
        T = NULL;
    else
    {
        int k = Search(ino, pre[ps], is, is + n - 1); // �ҵ����ĸ�����������е��±�ֵ���Դ������н���
        if (k == -1)                                  // ��ʾû���ҵ�
            T = NULL;
        else
        {
            T = (BiTNode *)malloc(sizeof(BiTNode)); // Ϊ���ڵ�����ռ�
            T->data = pre[ps];                      // ��ֵ���ݸ����ڵ�
            if (k == is)                            // Ҫ��k������������ĵ�һ��Ԫ�أ�˵�����������û������
                T->Lchild = NULL;
            else
                CrtBT(T->Lchild, pre, ino, ps + 1, is, k - is); // �ݹ齨��������
            if (k == is + n - 1)                                // Ҫ��k�����������������Ԫ�أ�˵�����������û���Һ���
                T->Rchild = NULL;
            else
                CrtBT(T->Rchild, pre, ino, ps + 1 + (k - is), k + 1, n - (k - is) - 1); // �ݹ齨��������
        }
    }
}

void PostTraversal(BiTree T)
{
    if (T)
    {
        PostTraversal(T->Lchild);
        PostTraversal(T->Rchild);
        std::cout << T->data << " ";
    }
}

int main()
{
    char pre[100], ino[100];
    int n;

    std::cout << "�������������г��ȣ�";
    std::cin >> n;

    std::cout << "�������������У�";
    for (int i = 0; i < n; i++)
        std::cin >> pre[i];

    std::cout << "�������������У�";
    for (int i = 0; i < n; i++)
        std::cin >> ino[i];

    BiTree T = NULL;
    CrtBT(T, pre, ino, 0, 0, n); // ���ǿ�ʼʱ���Ǵ��±�0��ʼ��

    std::cout << "������������";
    PostTraversal(T);
    std::cout << std::endl;

    return 0;
}
