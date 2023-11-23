// ˳��ջ
// https://blog.csdn.net/weixin_46475770/article/details/114077631
// ����ջ��ָ���ֵΪ-1��0������

#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int ElemType; // Ϊint������������
typedef int State;
typedef struct{   //˳��ջ�Ĵ洢�ṹ
    ElemType data[MAXSIZE];   //�����������ݣ����ΪMAXSIZE����Ϊջ������
    int top;   //����ջ��ָ��
}SqStack;

//��ʼ��˳��ջ
State initStack(SqStack *S){
    S->top = -1;   //��ջ��ָ����Ϊ-1������ջ��Ϊ���ǿյ�ʱ��
    // ���ʱ��ջ����ʱ��ջָ���ȼ�1������ֵ��ջ��Ԫ��
    return OK;
}

//���˳��ջ�ĳ���
int getLength(SqStack S){
    return (S.top)+1;   //���������±�Ĺ��������еĳ���Ϊָ��+1��Ԫ��
}

//���˳��ջ
State clearStack(SqStack *S){
    S->top = -1;   //��ջ��ָ����������Ϊ-1������ʱ��ʾջ��
    return OK;
}

//�ж�˳��ջ�Ƿ�Ϊ��
State isEmpty(SqStack S){
    if(S.top==-1){   //�����ʱջ��ָ��Ϊ-1��ʾջ��ʱΪ�գ���-1���ʾ�ǿ�
        return TRUE;
    }else{
        return FALSE;
    }
}

//��ջ
State push(SqStack *S, ElemType *e){
    if(S->top==MAXSIZE-1){   //���������±���ص㣬��ָ��ָ�����һ��Ԫ��ʱΪMAXSIZE-1����ʱջ��
        printf("ջ�����޷���ջ\n");
        return ERROR;   //ջ��˵���ռ������Ѿ�����������ջ
    }else{    //���ջ������ִ����ӹ���
        S->top++;   //ջ��ָ��+1ָ��һ���µĶ����ռ䣬��ջ���Ϸ��ƶ�һ����λ
        S->data[S->top]=e;   //������ָ�������µĿյ�ջ���ռ�Ԫ����Ϊָ��Ԫ�أ�����ȳ���
        return OK;
        // ����Ҫ���ƶ�ָ�룬�������Ԫ�صĹ���
    }
}

//��ջ��Ҳ�Ƶ�ջ
State pop(SqStack *S, ElemType *e){
    if(S->top==-1){   //��ջ��ָ��ָ��-1��˵��ջ�գ����޷���ջ
        printf("ջ�գ��޷���ջ\n");
        return ERROR;
    }else{   //���ջ�ǿ���ִ�г�ջ����
        *e = S->data[S->top];   //����ǰջ��Ԫ�ص�ָ�븳���ɹ����ز鿴��e
        S->top--;   //ջ��Ԫ�س�ջ��ջ��ָ��������һ�񣬱�ʾ�µ�ջ��Ԫ��
        return OK;
        // ����Ҫ�Ƚ���ָ����ָ���Ԫ��ɾ�������ٽ���ָ�������ƶ�һ����λ
    }
}

//��ȡջ��Ԫ�أ�ֻ���鿴������ջ����ȡ����ջ�������Ԫ��
State getTop(SqStack S, ElemType *e){
    if(S.top==-1){   //��ջ��ָ��ָ��-1��˵��ջ�գ�ջ��Ԫ��Ϊ��
        printf("ջ�գ���ջ��Ԫ��\n");
        return ERROR;
    }else{   //��ջ�ǿյ�ʱ����ջ��Ԫ�ظ�ֵ���ɹ����ز鿴��e������ջ��Ԫ�ز�����ջ
        *e = S.data[S.top];   //��ջ��Ԫ�ظ�ֵ��e��ջ��ָ��top����
        return OK;
    }
}

//������ӡ˳��ջ
State printStack(SqStack S){
    if(S.top==-1){   //��ջ��ָ��ָ��-1��˵��ջ�գ���ջԪ�ؿɹ���ӡ
        printf("ջ��,ջ��û��һ��Ԫ��\n");
        return ERROR;
    }
    int i=0;   //����������¼��ǰ�ǵڼ���Ԫ��
    while(S.top!=-1){
        i++;   //ջ��ָ�뻹δ��-1����˵����ǰջ��ָ����Ԫ�أ�������+1
        printf("ջ�����µ�%d��Ԫ��Ϊ:%d\n", i, S.data[S.top]);  //��ǰջ��ָ���Ԫ�ش�ӡ��
        S.top--;   //ջ��ָ��������һ�񣬼�������ѭ����ӡ
    }
    return OK;
}

//����
int main() {
    SqStack S;
    initStack(&S);
    printf("��ʼ���������ջ�ĳ���Ϊ��%d\n", getLength(S));
    printf("��1-5Ԫ��������ջ�ɵ�:\n");
    for(int i=1;i<=5;i++){
        push(&S, i);
    }
    printStack(S);
    printf("��ʱ˳��ջ�ĳ���Ϊ��%d\n", getLength(S));
    int e;
    pop(&S, &e);
    printf("��ջ��%d\n", e);
    pop(&S, &e);
    printf("��ջ��%d\n", e);
    printf("����˳��ջ�ĳ���Ϊ��%d\n", getLength(S));
    getTop(S, &e);
    printf("��ȡջ��Ԫ�أ�%d\n", e);
    printf("����˳��ջ�ĳ���Ϊ��%d\n", getLength(S));
    printf("����˳��ջ��Ϊ��\n");
    printStack(S);
    clearStack(&S);
    printf("���˳��ջ���ջΪ��\n");
    printStack(S);
    printf("����Ϊ��%d", getLength(S));
    return 0;
}
