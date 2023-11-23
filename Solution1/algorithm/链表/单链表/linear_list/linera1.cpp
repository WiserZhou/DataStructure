// ���Ա��˳��ʵ��
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h> // �����ں���ʵ��SetConsoleTitle����

//�������״̬���� 
#define TRUE     1     //�����г���TRUE�൱�ڳ�����1 
#define FALSE    0     //����FALSE�൱�ڳ�����0 
#define OK       1     //����OK�൱�ڳ�����1 
#define ERROR    0     //����ERROR�൱�ڳ�����0 
#define INFEASIBLE    -1
#define OVERFLOW      -2 

typedef int Status;
typedef int ElemType; 

#define LIST_INIT_SIZE    100     //���Ա�洢�ռ�ĳ�ʼ������ 
#define LISTINCREMENT     10      //���Ա�洢�ռ�ķ������� 

typedef struct{
	ElemType *elem;          //�洢�ռ�Ļ�ַ 
	int length;              //��ǰ���Ա�ĳ���
	int listsize;            //��ǰ���Ա�Ĵ洢����          
}SqList;

//����һ���յ����Ա�
Status InitList_Sq(SqList &L){
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));      //L.elemΪ��Ԫ�صĵ�ַ 
	if(!L.elem){            //����洢�ռ����ʧ�ܣ�L.elemΪNULL
	printf("�洢�ռ����ʧ��\n");
	exit(OVERFLOW);         
	}
	L.length = 0;            //��ǰ���Ա�Ϊ�ձ������Ա���Ϊ0
	L.listsize = LIST_INIT_SIZE;           //�����Ա�����ʼ����
	printf("һ���յ����Ա��Ѿ������ɹ�\n");      //��������Ա����ɹ�����ʾ��Ϣ 
	return OK; 
} 

//�����Ա���и�ֵ
Status ValueList_Sq(SqList &L){
	int i,j;
	printf("���������Ա�Ԫ�صĸ�����");
	scanf("%d",&i);
	if(i > L.listsize)                     //�����Ҫ�����Ԫ�ظ��������ڴ��Сʱ 
	{
		while(1)             //һֱ�����¿ռ䣬ֱ�����ٵĿռ������Ҫ�Ŀռ�Ϊֹ
		{
			if(i > L.listsize){
				L.elem = (ElemType *)realloc(L.elem,LISTINCREMENT * sizeof(ElemType));
				L.listsize += LISTINCREMENT;
        /*realloc()���������·���ռ�      
		           ������ԭ�ռ��ַ������ռ��С    
		           ���أ�1.�ɹ����¿ռ��ַ(��������һ����ֵ) 
		                 2.ʧ�ܣ�Null 
	    */ 
			}
			else
			break;
		}
	}
	for(j = 0;j < i;j++){
		printf("�������%d��Ԫ��:",j + 1);
	    scanf("%d",&L.elem[j]);	
	} 
	L.length = i;          //��ֵ��ɺ��޸Ĳ��������Ա�ĳ��� 
	printf("��ֵ�ɹ�\n");
	return OK; 
}

//�����Ա��������
Status DistoryList_Sq(SqList &L){
	if(!L.elem){   // �Ҳ������Ա���׵�ַ��˵����ʱ���Ա�û�н�����
	  printf("����δ�������Ա����Ƚ������Ա�\n");
	  return ERROR; 
	} 
	free(L.elem);            //ʹ��free��������֮ǰ��̬������ڴ滹��ϵͳ 
	L.elem = NULL;           //����elem��ֵΪNull 
	L.length = 0;            //�����Ա��Ԫ�ظ�������Ϊ0
	L.listsize = 0;          //�����Ա�Ĵ洢��������Ϊ0 
	printf("���Ա��Ѿ�����\n"); 
	return OK;
}

//�����Ա��������
Status ClearList_Sq(SqList &L){
	if(L.elem){                  //������Ա���� 
	    L.length = 0;            //�����Ա��Ԫ�ظ�������Ϊ0
	    printf("���Ա�������\n");
	    return OK;
	}
	else 
	printf("���Ա����ڣ��޷�����\n");
	return OK;
} 

//�ж����Ա��Ƿ�Ϊ��
Status ListEmpty_Sq(SqList L){
	if(L.elem){          //�ж����Ա��Ƿ�Ϊ�յ�ǰ�������Ա���ڣ�����Ԫ�ص�ַ��L.elem����ʱ˵�����Ա���� 
		if(L.length != 0){               //������Ա���Ԫ��Ϊ0����L.length��ֵΪ0ʱ˵�����Ա��ǿձ� 
		       printf("���Ա��ǿձ�\n");
		       return FALSE; 
			}
			else
			   printf("���Ա��ǿձ�\n");
		return TRUE;
	}
	else
	printf("���Ա����ڣ��޷��ж�\n");
	return OK; 
}

//��ȡ���Ա�ĳ���
Status ListLength_Sq(SqList L){
	if(L.elem){              //�жϵ�ǰ���Ա���� 
		int K;
		K = L.length;        //�����Ա��Ԫ�ظ�����ֵ��K
		printf("���Ա���Ϊ%d\n",K); 
		return OK; 
	}
	else
		printf("���Ա����ڣ��޷��ж�\n");
	return OK;
}

//��ȡ���Ա�ĳһλ�ö�Ӧ��Ԫ��
Status GetElem_Sq(SqList L,int index){
	int Num;
	if(index <= 0 || index > L.length){              //���Ҫ��ȡԪ�ص�λ���Ƿ���� 
		printf("������һ����Ч������\n");
		return ERROR;
	}
	else
	Num = L.elem[index - 1];
	printf("��%d��λ�õ�Ԫ��Ϊ:%d\n",index,Num);
	return OK;
} 

//�����Ա�ĳһλ�ò���Ԫ��
Status ListInsert_Sq(SqList &L,int i,ElemType e){
	ElemType *newbase;
	int *q,*p; 
	if(i < 1 || i > L.length+1)         //�жϲ���λ�õ�indexֵ�Ƿ�Ϸ�      
	    return ERROR; 
	if(L.length >= L.listsize){         //�����ǰ���Ա�洢�ռ����������ӷ��� 
		newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)  {                 //����洢�ռ����ʧ�ܣ���ִ���쳣�˳� 
			printf("�洢�ռ����ʧ��\n");
			exit(OVERFLOW);
		}
		L.elem = newbase;               //�µĴ洢�ռ��ַ,�����µĴ洢�ռ�������ַ
		L.listsize += LISTINCREMENT; 
	}
	q = &(L.elem[i-1]);                 //L.elem[index-1]Ϊ�����е����һ��Ԫ�أ�qΪҪ�����λ�� 
	for(p = &(L.elem[L.length - 1]);p >= q;--p)
	    *(p+1) = *p;                    //Ҫ����λ���Լ�֮���λ������� 
	*q = e;                             //��e���뵽��Ҫ�����λ�� 
	++L.length;                         //�����µ�Ԫ��֮�����1 
	printf("Ԫ�ز���ɹ�\n");
	return OK;
}

//��ӡ���Ա�
Status PrintList_Sq(SqList L){
	printf("��ǰ���Ա��Ԫ��Ϊ��");
	for(int K = 0;K < L.length;K++)      //������ǰ���Ա� 
	    printf("  %d",L.elem[K]);
	printf("\n");                        //���� 
	return OK;
} 

//ɾ�����Ա�ĳһλ�õ�Ԫ��
Status DeleteList_Sq(SqList &L,int i){
	int *p,*q;
	if(i < 1 || i > L.length){            //���Ҫɾ����λ�ò��Ϸ�
		printf("������һ����Ч����\n"); 
		return ERROR;
	} 
	p = &(L.elem[i - 1]);                 //pΪ��ɾ��Ԫ�ص�λ��
	//q = L.elem + L.length - 1;            //����βԪ�ص�λ�ø�ֵ��q
	q=&(L.elem[L.length-1]);
	for(++p;p <= q;p++)
	    *(p - 1) = *p;                    //��ɾ����Ԫ��֮���Ԫ��ȫ������ 
	--L.length;                           //����1 
	printf("��%d��Ԫ��ɾ���ɹ�\n",i);
	return OK;
}

//�����Ա�ĳһԪ�ص�ǰ��
Status PriorElem_Sq(SqList L,int i){
	int K;
	if(L.elem){          //�ж����Ա��Ƿ�Ϊ�յ�ǰ�������Ա���ڣ�����Ԫ�ص�ַ��L.elem����ʱ˵�����Ա����
	    if(i <= 1 || i > L.length + 1)              //�ж������iֵ�Ƿ�Ϸ� 
	        {
				printf("�������벻���Ϲ淶��");
				printf("������һ����Ч����\n");
				return ERROR;
			}
		K = L.elem[i - 2];        //����i��Ԫ�ص�ǰһ��Ԫ�ظ�ֵ��K
		printf("��%d��λ�õ�ֱ��ǰ��Ϊ:%d\n",i,K); 
	}
	else
		printf("���Ա����ڣ��޷��ж�\n");
	return OK;
} 

//�����Ա�ĳһԪ�صĺ�� 
Status NextElem_Sq(SqList L,int i){
	int K;
	if(L.elem){          //�ж����Ա��Ƿ�Ϊ�յ�ǰ�������Ա���ڣ�����Ԫ�ص�ַ��L.elem����ʱ˵�����Ա����
	    if(i <= 1 || i > L.length - 1)              //�ж������iֵ�Ƿ�Ϸ� 
	        {
				printf("�������벻���Ϲ淶��");
				printf("������һ����Ч����\n");
				return ERROR;
			}
		K = L.elem[i];        //����i��Ԫ�صĺ�һ��Ԫ�ظ�ֵ��K
		printf("��%d��λ�õ�ֱ�Ӻ��Ϊ:%d\n",i,K); 
	}
	else
		printf("���Ա����ڣ��޷��ж�\n");
	return OK;
} 

int main(){
	// SetConsoleTitle("������д�����Ա�");  // Ҫ��ʾ�ڿ���̨���ڱ������е��ַ����� �ܴ�С����С�� 64K��
	SqList L;
	int choose,index,e;
	while(1){
		printf("*****************************************\n");
		printf("*                                       *\n");
		printf("*  ���Ա��˳���ʾ��ʵ�֣�             *\n");
		printf("*                                       *\n");
		printf("*    1.  ����һ���յ����Ա�             *\n");
		printf("*    2.  �����Ա���и�ֵ               *\n");
		printf("*    3.  �����Ա��������               *\n");
		printf("*    4.  �����Ա��������               *\n"); 
		printf("*    5.  �ж����Ա��Ƿ�Ϊ��             *\n");
		printf("*    6.  ��ȡ���Ա�ĳ���               *\n");
		printf("*    7.  ��ȡ���Ա�ĳһλ�ö�Ӧ��Ԫ��   *\n");
		printf("*    8.  �����Ա�ĳһλ�ò���Ԫ��       *\n");
		printf("*    9.  ɾ�����Ա�ĳһλ�õ�Ԫ��       *\n");
		printf("*    10. �����Ա�ĳһԪ�ص�ǰ��         *\n");
		printf("*    11. �����Ա�ĳһԪ�صĺ��         *\n");
		printf("*    12. ��ӡ���Ա�                     *\n");
		printf("*    13. �˳�                           *\n");
		printf("*                                       *\n");
		printf("*****************************************\n");
		printf("����������ѡ��");
		scanf("%d",&choose);
		switch(choose){
			case 1:InitList_Sq(L);break;
			case 2:ValueList_Sq(L);break;
			case 3:DistoryList_Sq(L);break;
			case 4:ClearList_Sq(L);break;
			case 5:ListEmpty_Sq(L);break;
			case 6:ListLength_Sq(L);break;
			case 7:{
				printf("������Ҫ��ȡԪ�ص�λ�ã�");
				scanf("%d",&index);
				GetElem_Sq(L,index);
			}
			break;
			case 8:{
				printf("������Ҫ����Ԫ�ص�λ�ã�");
				scanf("%d",&index);
				printf("������Ҫ�����Ԫ�أ�");
				scanf("%d",&e);
				ListInsert_Sq(L,index,e);
			}
			break;
			case 9:{
				printf("������Ҫɾ��Ԫ�ص�λ�ã�");
				scanf("%d",&index);
				DeleteList_Sq(L,index);	
			}
			break;
			case 10:{
				printf("��������Ҫ������һ��Ԫ�ص�ǰ����");
				scanf("%d",&index);
				PriorElem_Sq(L,index);
			}
			break;
			case 11:{
				printf("��������Ҫ������һ��Ԫ�صĺ�̣�");
				scanf("%d",&index);
				NextElem_Sq(L,index);
			}
			break; 
			case 12:PrintList_Sq(L);break;
			case 13:exit(0);
		}
	}
	return 0;
}
