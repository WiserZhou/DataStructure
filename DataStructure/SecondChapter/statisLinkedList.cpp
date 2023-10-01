#include <stdio.h>
#include <stdlib.h>

#define maxSize 6

typedef struct
{
    int data;
    int cur; // 游标
} component;

/*************************************************************************
创建备用链表
*****************************************************************************/
void reserveArr(component *array)
{
    int i;
    for (i = 0; i < maxSize; i++)
    {
        array[i].cur = i + 1; // 将每个数组分量链接到一起
    }
    array[maxSize - 1].cur = 0; // 链表最后一个节点的游标为0
}

/********************************************************
提取分配空间
若备用链表为非空，则返回分配的节点下标，否则返回0(当分配最后一个节点时，该节点的游标值为0)
********************************************************/
int mallocArr(component *array)
{
    int i = array[0].cur;

    if (array[0].cur)
    {
        // array[0].data=0;
        array[0].cur = array[i].cur;
    }
    return i;
}

/***************************************************************************
初始化静态链表
****************************************************************************/
int initArr(component *array)
{
    int body, tempBody, i, j;
    reserveArr(array);
    body = mallocArr(array);
    tempBody = body; // 声明一个变量把它当指针使，指向链表的最后一个节点，因为链表为空，所以和头结点重合
    for (i = 1; i < 4; i++)
    {
        j = mallocArr(array);    // 从备用链表中拿出空闲的分量
        array[tempBody].cur = j; // 将申请的空闲分量链接在链表的最后一个结点后面
        array[j].data = i;       // 给新申请的分量数据域初始化
        tempBody = j;            // 将指向链表最后一个结点的指针后移
    }
    array[tempBody].cur = 0; // 新的链表最后一个结点的指针设为0
    return body;
}

void displayArr(component *array, int body)
{
    int tempBody = body; // tempBody准备遍历使用
    while (array[tempBody].cur)
    {
        printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
        tempBody = array[tempBody].cur;
    }
    printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
}

int main()
{
    int body;
    component array[maxSize];
    body = initArr(array);
    printf("static link:\n");
    displayArr(array, body);

    system("pause");
    return 0;
}

void Insert(component *array, int body, int add, int a) // body链表头结点在数组中的位置，add插入元素的位置，a插入的元素
{
    int tempBody = body;
    int i, insert;
    for (i = 1; i < add; i++)
    {
        tempBody = array[tempBody].cur;
    }
    insert = mallocArr(array);
    array[insert].data = a;
    array[insert].cur = array[tempBody].cur;
    array[tempBody].cur = insert;
}

// 备用链表回收空间的函数，其中array为存储数据的数组，k表示未使用节点所在数组的下标
void freeArr(component *array, int k)
{
    array[k].cur = array[0].cur;
    array[0].cur = k;
}
// 删除结点函数，a 表示被删除结点中数据域存放的数据
void deleteArr(component *array, int body, char a)
{
    int tempBody = body;
    // 找到被删除结点的位置
    while (array[tempBody].data != a)
    {
        tempBody = array[tempBody].cur;
        // 当tempBody为0时，表示链表遍历结束，说明链表中没有存储该数据的结点
        if (tempBody == 0)
        {
            printf("链表中没有此数据");
            return;
        }
    }
    // 运行到此，证明有该结点
    int del = tempBody;
    tempBody = body;
    // 找到该结点的上一个结点，做删除操作
    while (array[tempBody].cur != del)
    {
        tempBody = array[tempBody].cur;
    }
    // 将被删除结点的游标直接给被删除结点的上一个结点
    array[tempBody].cur = array[del].cur;
    // 回收被摘除节点的空间
    freeArr(array, del);
}

/********************************************************
在以body作为头结点的链表中查找数据域为elem的结点在数组中的位置
*****************************************************/
int selectElem(component *array, int body, char elem)
{
    int tempBody = body;
    while (array[tempBody].cur != 0) // 当游标值为0时，表示链表结束
    {
        if (array[tempBody].data == elem)
        {
            return tempBody;
        }
        tempBody = array[tempBody].cur;
    }
    return -1; // 返回-1，表示在链表中没有找到该元素
}

/********************************************************
在以body作为头结点的链表中将数据域为oldElem的结点，数据域改为newElem
**********************************************************/
void amendElem(component *array, int body, char oldElem, char newElem)
{
    int add = selectElem(array, body, oldElem);
    if (add == -1)
    {
        printf("无更改元素");
        return;
    }
    array[add].data = newElem;
}