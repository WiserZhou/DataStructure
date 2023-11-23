// 顺序栈
// https://blog.csdn.net/weixin_46475770/article/details/114077631
// 关于栈顶指针初值为-1和0的区别

#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int ElemType; // 为int类型重命名了
typedef int State;
typedef struct{   //顺序栈的存储结构
    ElemType data[MAXSIZE];   //用数组存放数据，最大为MAXSIZE，作为栈满条件
    int top;   //用作栈顶指针
}SqStack;

//初始化顺序栈
State initStack(SqStack *S){
    S->top = -1;   //将栈顶指针置为-1，即将栈作为还是空的时候
    // 这个时候，栈不满时，栈指针先加1，再送值到栈顶元素
    return OK;
}

//获得顺序栈的长度
int getLength(SqStack S){
    return (S.top)+1;   //根据数组下标的规则，数组中的长度为指针+1个元素
}

//清空顺序栈
State clearStack(SqStack *S){
    S->top = -1;   //将栈顶指针重新设置为-1，即此时表示栈空
    return OK;
}

//判断顺序栈是否为空
State isEmpty(SqStack S){
    if(S.top==-1){   //如果此时栈顶指针为-1表示栈此时为空，非-1则表示非空
        return TRUE;
    }else{
        return FALSE;
    }
}

//入栈
State push(SqStack *S, ElemType *e){
    if(S->top==MAXSIZE-1){   //根据数组下标的特点，当指针指向最后一个元素时为MAXSIZE-1，此时栈满
        printf("栈满，无法入栈\n");
        return ERROR;   //栈满说明空间已满已经不可以再入栈
    }else{    //如果栈非满则执行添加过程
        S->top++;   //栈顶指针+1指向一个新的顶部空间，向栈的上方移动一个单位
        S->data[S->top]=e;   //将现在指向的这个新的空的栈顶空间元素置为指定元素（后进先出）
        return OK;
        // 这里要先移动指针，再行添加元素的过程
    }
}

//出栈，也称弹栈
State pop(SqStack *S, ElemType *e){
    if(S->top==-1){   //当栈顶指针指向-1，说明栈空，则无法出栈
        printf("栈空，无法出栈\n");
        return ERROR;
    }else{   //如果栈非空则执行出栈程序
        *e = S->data[S->top];   //将当前栈顶元素的指针赋给可供返回查看的e
        S->top--;   //栈顶元素出栈后，栈顶指针向下走一格，表示新的栈顶元素
        return OK;
        // 这里要先将顶指针所指向的元素删除掉，再将顶指针向下移动一个单位
    }
}

//获取栈顶元素（只供查看，不出栈）获取的是栈最上面的元素
State getTop(SqStack S, ElemType *e){
    if(S.top==-1){   //当栈顶指针指向-1，说明栈空，栈顶元素为空
        printf("栈空，无栈顶元素\n");
        return ERROR;
    }else{   //当栈非空的时候，则将栈顶元素赋值给可供返回查看的e，但是栈顶元素并不出栈
        *e = S.data[S.top];   //将栈顶元素赋值给e，栈顶指针top不变
        return OK;
    }
}

//遍历打印顺序栈
State printStack(SqStack S){
    if(S.top==-1){   //当栈顶指针指向-1，说明栈空，无栈元素可供打印
        printf("栈空,栈中没有一个元素\n");
        return ERROR;
    }
    int i=0;   //计数器，记录当前是第几个元素
    while(S.top!=-1){
        i++;   //栈顶指针还未到-1，则说明当前栈顶指针有元素，计数器+1
        printf("栈顶向下第%d个元素为:%d\n", i, S.data[S.top]);  //当前栈顶指针的元素打印出
        S.top--;   //栈顶指针向下走一格，继续进行循环打印
    }
    return OK;
}

//测试
int main() {
    SqStack S;
    initStack(&S);
    printf("初始化后的线性栈的长度为：%d\n", getLength(S));
    printf("将1-5元素依次入栈可得:\n");
    for(int i=1;i<=5;i++){
        push(&S, i);
    }
    printStack(S);
    printf("此时顺序栈的长度为：%d\n", getLength(S));
    int e;
    pop(&S, &e);
    printf("出栈：%d\n", e);
    pop(&S, &e);
    printf("出栈：%d\n", e);
    printf("现在顺序栈的长度为：%d\n", getLength(S));
    getTop(S, &e);
    printf("获取栈顶元素：%d\n", e);
    printf("现在顺序栈的长度为：%d\n", getLength(S));
    printf("现在顺序栈的为：\n");
    printStack(S);
    clearStack(&S);
    printf("清空顺序栈后的栈为：\n");
    printStack(S);
    printf("长度为：%d", getLength(S));
    return 0;
}
