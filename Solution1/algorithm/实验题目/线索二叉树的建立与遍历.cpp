/********************************
��������Ľ��������������Ϊchar������ɣ�

(1) ���ݴ��յ���׺������һ�ö�����T

(2) ����T����������������Thrt

(3) ����Thrtʵ��T�����������������������

(4) ���Thrt��һ�Ƚ�������

�������⣬�����߼��ṹ���µ�һ�ö��������ԣ�

      A
     / \
    B   D
     \
      C
����������Ϊ:

AB#C##D##
���������Ϊ:

BCAD
2
ͬ�������������߼��ṹ�Ķ��������ԣ�

           -
        /     \
      +        /
     / \      / \
    a   b    d   e
����������Ϊ��

-+a##b##/d##e##
���������Ϊ��

a+b-d/e
1
����˵����

(1) ����������'#'��ʾ����

(2) ��������ĵ�һ�д�����������Ľ��

(3) ��������ĵڶ��б�ʾ������������һ�Ƚڵ������
*********************************/
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct BiThrNode//�������������ṹ
{
    char data;
    struct  BiThrNode *lchild,*rchild;
    bool LTag,RTag;//����������־
} BiThrNode,*BiThrTree;
void CreateBiTree(BiThrTree &T)//������׺������
{
    char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else
    {
        T=(BiThrNode *)malloc(sizeof(BiThrNode));
        T->data=ch;
        T->LTag=0;//Ĭ��Ϊ0,Ҳ����:T->LTag=(T->lchild==NULL)?1:0;
        T->RTag=0;//Ĭ��Ϊ0,Ҳ����:T->RTag=(T->rchild==NULL)?1:0;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
BiThrTree pre;//ȫ�ֱ���
void InThreading(BiThrTree p)//������������pΪ������
{
    if(p)
    {
        InThreading(p->lchild);//������������
        if(!p->lchild)// ��ǰ������
        {
            p->LTag=1;
            p->lchild=pre;
        }
        if(!pre->rchild)// ���������
        {
            pre->RTag=1;
            pre->rchild=p;

        }
        pre=p;// ���� pre ָ�� p ��ǰ��
        InThreading(p->rchild);//������������
    }
}
bool InOrderThreading(BiThrTree &Thrt,BiThrTree T) //����������������
{
    Thrt=(BiThrTree)malloc(sizeof(BiThrNode));//����ͷ���
    Thrt->LTag=0;
    Thrt->RTag=1;
    Thrt->rchild=Thrt;

    if(!T) Thrt->lchild=Thrt;//���T�ǿ���
    else
    {
        Thrt->lchild=T;//��������Ϊ��ʼ��Thrd��������ָ��������������ThrdΪ���ӵ�ͷ���
        pre=Thrt;

        InThreading(T);


        pre->rchild=Thrt;// �������䴦�����һ�����,��ʱThrdΪ����pre Ϊ���һ�����
        pre->RTag=1;
        Thrt->rchild=pre;
    }
    return true;
}
void InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p=T->lchild;
    while(p!=T)// �������������ʱ��p==T
    {
        while(p->LTag==0) p=p->lchild;//�������½��
        cout<<p->data;//�����ҵ��ĵ�һ�����
        while(p->RTag==1&&p->rchild!=T)//���ʺ�̽��
        {
            p=p->rchild;
            cout<<p->data;
        }
        p=p->rchild;//���p��������Ϊ0����p����ָ��ΪT����������������
    }
}
void CountOneChild(BiThrTree T,int &c)//����Ҷ�ӽڵ�����
{


    BiThrTree p=T->lchild;
    while(p!=T)// �������������ʱ��p==T
    {
        while(p->LTag==0) p=p->lchild;//�������½��
        if(!p->RTag)//���p��������������p��1�Ƚ��
            c++;
        while(p->RTag==1&&p->rchild!=T)//���ʺ�̽��
        {
            p=p->rchild;
            if(((!p->LTag)&&(p->RTag))||((p->LTag)&&(!p->RTag)))//���p��1�Ƚ��
                c++;
        }
        p=p->rchild;//���p��������Ϊ0����p����ָ��ΪT����������������
    }

}
int main()
{
    BiThrTree T,Thrd;
    CreateBiTree(T);//����������
    InOrderThreading(Thrd,T);//������������
    InOrderTraverse_Thr(Thrd);//������������
    cout<<endl;
    int c=1;
    CountOneChild(Thrd,c);
    cout<<c;
    return 0;
}

