/********************************
设二叉树的结点的数据域的类型为char，请完成：

(1) 根据带空的先缀串建立一棵二叉树T

(2) 构建T的中序线索二叉树Thrt

(3) 基于Thrt实现T的中序遍历，并输出遍历结果

(4) 输出Thrt中一度结点的数量

根据题意，对于逻辑结构如下的一棵二叉树而言：

      A
     / \
    B   D
     \
      C
其输入用例为:

AB#C##D##
其输出用例为:

BCAD
2
同样，对于如下逻辑结构的二叉树而言：

           -
        /     \
      +        /
     / \      / \
    a   b    d   e
其输入用例为：

-+a##b##/d##e##
其输出用例为：

a+b-d/e
1
用例说明：

(1) 输入用例中'#'表示空树

(2) 输出用例的第一行代表中序遍历的结果

(3) 输出用例的第二行表示线索二叉树上一度节点的数量
*********************************/
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct BiThrNode//线索二叉树结点结构
{
    char data;
    struct  BiThrNode *lchild,*rchild;
    bool LTag,RTag;//左右线索标志
} BiThrNode,*BiThrTree;
void CreateBiTree(BiThrTree &T)//根据先缀串建树
{
    char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else
    {
        T=(BiThrNode *)malloc(sizeof(BiThrNode));
        T->data=ch;
        T->LTag=0;//默认为0,也可以:T->LTag=(T->lchild==NULL)?1:0;
        T->RTag=0;//默认为0,也可以:T->RTag=(T->rchild==NULL)?1:0;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
BiThrTree pre;//全局变量
void InThreading(BiThrTree p)//中序线索化以p为根的树
{
    if(p)
    {
        InThreading(p->lchild);//左子树线索化
        if(!p->lchild)// 建前驱线索
        {
            p->LTag=1;
            p->lchild=pre;
        }
        if(!pre->rchild)// 建后继线索
        {
            pre->RTag=1;
            pre->rchild=p;

        }
        pre=p;// 保持 pre 指向 p 的前驱
        InThreading(p->rchild);//右子树线索化
    }
}
bool InOrderThreading(BiThrTree &Thrt,BiThrTree T) //构建中序线索链表
{
    Thrt=(BiThrTree)malloc(sizeof(BiThrNode));//构建头结点
    Thrt->LTag=0;
    Thrt->RTag=1;
    Thrt->rchild=Thrt;

    if(!T) Thrt->lchild=Thrt;//如果T是空树
    else
    {
        Thrt->lchild=T;//下面两句为初始化Thrd的左子树指向真正的树根，Thrd为增加的头结点
        pre=Thrt;

        InThreading(T);


        pre->rchild=Thrt;// 下面三句处理最后一个结点,此时Thrd为根，pre 为最后一个结点
        pre->RTag=1;
        Thrt->rchild=pre;
    }
    return true;
}
void InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p=T->lchild;
    while(p!=T)// 空树或遍历结束时，p==T
    {
        while(p->LTag==0) p=p->lchild;//找最左下结点
        cout<<p->data;//访问找到的第一个结点
        while(p->RTag==1&&p->rchild!=T)//访问后继结点
        {
            p=p->rchild;
            cout<<p->data;
        }
        p=p->rchild;//如果p的右线索为0，或p的右指针为T，进至其右子树根
    }
}
void CountOneChild(BiThrTree T,int &c)//计算叶子节点数量
{


    BiThrTree p=T->lchild;
    while(p!=T)// 空树或遍历结束时，p==T
    {
        while(p->LTag==0) p=p->lchild;//找最左下结点
        if(!p->RTag)//如果p有右子树，表明p是1度结点
            c++;
        while(p->RTag==1&&p->rchild!=T)//访问后继结点
        {
            p=p->rchild;
            if(((!p->LTag)&&(p->RTag))||((p->LTag)&&(!p->RTag)))//如果p是1度结点
                c++;
        }
        p=p->rchild;//如果p的右线索为0，或p的右指针为T，进至其右子树根
    }

}
int main()
{
    BiThrTree T,Thrd;
    CreateBiTree(T);//构建二叉树
    InOrderThreading(Thrd,T);//构建中序链表
    InOrderTraverse_Thr(Thrd);//遍历中序链表
    cout<<endl;
    int c=1;
    CountOneChild(Thrd,c);
    cout<<c;
    return 0;
}

