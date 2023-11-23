#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
struct MinHeapNode
{
   char data;
   unsigned freq;
   struct MinHeapNode *left, *right;
};

// 定义最小堆结构
struct MinHeap
{
   unsigned size;
   unsigned capacity;
   struct MinHeapNode **array;
};

// 创建最小堆节点
struct MinHeapNode *newNode(char data, unsigned freq)
{
   struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
   temp->left = temp->right = NULL;
   temp->data = data;
   temp->freq = freq;
   return temp;
}

// 创建最小堆
struct MinHeap *createMinHeap(unsigned capacity)
{
   struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
   minHeap->size = 0;
   minHeap->capacity = capacity;
   minHeap->array = (struct MinHeapNode **)malloc(capacity * sizeof(struct MinHeapNode *));
   return minHeap;
}

// 交换最小堆中的两个节点
void swapMinHeapNodes(struct MinHeapNode **a, struct MinHeapNode **b)
{
   struct MinHeapNode *t = *a;
   *a = *b;
   *b = t;
}

// 维护最小堆性质
void minHeapify(struct MinHeap *minHeap, int idx)
{
   int smallest = idx;
   int left = 2 * idx + 1;
   int right = 2 * idx + 2;

   if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
      smallest = left;

   if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
      smallest = right;

   if (smallest != idx)
   {
      swapMinHeapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
      minHeapify(minHeap, smallest);
   }
}

// 判断最小堆是否只包含一个节点
int isSizeOne(struct MinHeap *minHeap)
{
   return (minHeap->size == 1);
}

// 提取最小堆中的最小节点
struct MinHeapNode *extractMin(struct MinHeap *minHeap)
{
   struct MinHeapNode *temp = minHeap->array[0];
   minHeap->array[0] = minHeap->array[minHeap->size - 1];
   --minHeap->size;
   minHeapify(minHeap, 0);
   return temp;
}

// 插入新节点到最小堆中
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode)
{
   ++minHeap->size;
   int i = minHeap->size - 1;
   while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
   {
      minHeap->array[i] = minHeap->array[(i - 1) / 2];
      i = (i - 1) / 2;
   }
   minHeap->array[i] = minHeapNode;
}

// 构建赫夫曼树
struct MinHeapNode *buildHuffmanTree(char data[], int freq[], int size)
{
   struct MinHeapNode *left, *right, *top;
   struct MinHeap *minHeap = createMinHeap(size);

   for (int i = 0; i < size; ++i)
      insertMinHeap(minHeap, newNode(data[i], freq[i]));

   while (!isSizeOne(minHeap))
   {
      left = extractMin(minHeap);
      right = extractMin(minHeap);

      top = newNode('$', left->freq + right->freq);

      top->left = left;
      top->right = right;

      insertMinHeap(minHeap, top);
   }

   return extractMin(minHeap);
}

// 打印赫夫曼树的编码
void printCodes(struct MinHeapNode *root, int arr[], int top)
{
   if (root->left)
   {
      arr[top] = 0;
      printCodes(root->left, arr, top + 1);
   }

   if (root->right)
   {
      arr[top] = 1;
      printCodes(root->right, arr, top + 1);
   }

   if (!(root->left) && !(root->right))
   {
      printf("%c: ", root->data);
      for (int i = 0; i < top; ++i)
         printf("%d", arr[i]);
      printf("\n");
   }
}

int main()
{
   char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
   int freq[] = {5, 9, 12, 13, 16, 45};

   int size = sizeof(data) / sizeof(data[0]);

   struct MinHeapNode *root = buildHuffmanTree(data, freq, size);

   int arr[100], top = 0;
   printf("Huffman Codes:\n");
   printCodes(root, arr, top);

   return 0;
}
