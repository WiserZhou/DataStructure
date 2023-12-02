#include <stdio.h>
#include <stdlib.h>
// 定义栈结构
typedef struct
{
    int top;      // 栈顶指针
    int capacity; // 栈容量
    int *array;   // 存储栈元素的数组
} Stack;
// 创建栈,也就是初始化栈
Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));               // 分配内存以创建栈结构
    stack->capacity = capacity;                                  // 设置栈容量
    stack->top = -1;                                             // 初始化栈顶指针为-1，表示栈为空
    stack->array = (int *)malloc(stack->capacity * sizeof(int)); // 根据栈容量分配存储空间
    return stack;
}
// 判断栈是否为空
int isEmpty(Stack *stack)
{
    return stack->top == -1; // 这是一段判断语句
}
// 判断栈是否已满
int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}
// 入栈，要判断一下栈是否已经满了
void push(Stack *stack, int item)
{
    if (isFull(stack)) // 栈已满，无法入栈
        return;
    stack->array[++stack->top] = item; // 栈顶指针加1，并将元素入栈
}
// 出栈
int pop(Stack *stack)
{
    if (isEmpty(stack)) // 栈为空
        return -1;
    return stack->array[stack->top--]; // 栈顶指针减1，并返回栈顶元素
}
// 十进制转换函数
void decimalToOtherBase(int decimal, int base)
{
    Stack *stack = createStack(100); // 创建一个容量为100的栈
    if (decimal == 0)
    {
        printf("0"); // 如果待转换的十进制数为0，则直接输出0
        return;
    }
    while (decimal > 0)
    {
        push(stack, decimal % base); // 将余数入栈
        decimal /= base;             // 十进制数除以进制数，更新十进制数的值
    }
    while (!isEmpty(stack))
    {
        int digit = pop(stack); // 依次出栈得到每一位的值
        // 如果是16进制且数值大于等于10，则将对应的值转换成大写字母输出
        if (base == 16 && digit >= 10)
            printf("%c", 'A' + digit - 10);
        else
            printf("%d", digit); // 输出对应位的值
    }
    free(stack->array); // 释放栈数组的内存
    free(stack);        // 释放栈结构的内存
    // 假设只执行一次 free(stack)，而不释放栈数组的内存，
    // 那么栈数组的内存将无法被访问到，从而导致内存泄漏。释放栈数组的内存之后，再次释放栈本身的内存可以避免这种情况发生
}
int main()
{
    int decimal, base; // decimal 代表的是十进制数，base代表的是需要转换的进制数
    scanf("%d", &decimal);
    scanf("%d", &base);
    decimalToOtherBase(decimal, base);
    return 0;
}