

// �ô���ʹ������Ԫ��ķ�ʽ��ʾϡ����󡣽ṹ�� OLNode ��ʾ�����еķ���Ԫ�أ�
// �����кš��кź�Ԫ�ص�ֵ���Լ�����ָ���� right �� down ���������Ҳ���·���Ԫ�ء�
// �ṹ�� CrossList ��ʾ����ϡ����󣬰���������ͷָ������ rhead��������ͷָ������ chead��
// �ֱ����ڴ洢ÿһ�к�ÿһ�е�����ͷָ�롣ͬʱ����¼�˾���������������ͷ���Ԫ�ظ�����
// CreateMatrix_OL �������ڴ���ϡ������ȸ����û�����������������ͷ���Ԫ�ظ�����ʼ��ϡ���������ԣ�
// Ȼ��ͨ�������û�����ķ���Ԫ�أ�������Ӧ�Ľ�㣬�������������������ķ�ʽ����������
// display �����������ϡ����󣬱��������������ÿ�������кš��кź�Ԫ�ص�ֵ��
// �� main �����У���ʼ�����󲢵��� CreateMatrix_OL ��������ϡ����������� display �������ϡ�����
#include <stdio.h>
#include <stdlib.h>

// ϡ��������Ԫ���ʾ
typedef struct OLNode
{
    int i, j, e;                 // ������Ԫ�� i������ j������ e����ǰλ�õ�����
    struct OLNode *right, *down; // ָ���� ��ָ�� ��ָ��
} OLNode, *OLink;

typedef struct
{
    OLink *rhead, *chead; // �к�������ͷָ��
    int mu, nu, tu;       // ���������,�����ͷ���Ԫ�ĸ���
} CrossList;

// ����ϡ�����
CrossList CreateMatrix_OL(CrossList M);
// ���ϡ�����
void display(CrossList M);

int main()
{
    CrossList M;
    M.rhead = NULL;
    M.chead = NULL;
    M = CreateMatrix_OL(M);
    printf("�������M:\n");
    display(M);
    return 0;
}

CrossList CreateMatrix_OL(CrossList M)
{
    int m, n, t;
    int i, j, e;
    OLNode *p, *q;

    printf("�������������������ͷ���Ԫ�ظ�����");
    scanf("%d%d%d", &m, &n, &t);

    M.mu = m;
    M.nu = n;
    M.tu = t;

    // �����к�������ͷָ��������ڴ�ռ�
    if (!(M.rhead = (OLink *)malloc((m + 1) * sizeof(OLink))) || !(M.chead = (OLink *)malloc((n + 1) * sizeof(OLink))))
    {
        printf("��ʼ������ʧ��");
        exit(0);
    }

    // ��ʼ��������ͷָ�������������ͷָ������
    for (i = 1; i <= m; i++)
    {
        M.rhead[i] = NULL;
    }
    for (j = 1; j <= n; j++)
    {
        M.chead[j] = NULL;
    }

    // �������Ԫ�ص��кš��кź�ֵ
    for (scanf("%d%d%d", &i, &j, &e); 0 != i; scanf("%d%d%d", &i, &j, &e))
    {
        // �����½�㲢��ֵ
        if (!(p = (OLNode *)malloc(sizeof(OLNode))))
        {
            printf("��ʼ����Ԫ��ʧ��");
            exit(0);
        }
        p->i = i;
        p->j = j;
        p->e = e;

        // ���ӵ��е�ָ��λ��
        if (NULL == M.rhead[i] || M.rhead[i]->j > j)
        {
            p->right = M.rhead[i];
            M.rhead[i] = p;
        }
        else
        {
            for (q = M.rhead[i]; (q->right) && q->right->j < j; q = q->right)
                ;
            p->right = q->right;
            q->right = p;
        }

        // ���ӵ��е�ָ��λ��
        if (NULL == M.chead[j] || M.chead[j]->i > i)
        {
            p->down = M.chead[j];
            M.chead[j] = p;
        }
        else
        {
            for (q = M.chead[j]; (q->down) && q->down->i < i; q = q->down)
                ;
            p->down = q->down;
            q->down = p;
        }
    }

    return M;
}

void display(CrossList M)
{
    for (int i = 1; i <= M.nu; i++)
    {
        if (NULL != M.chead[i])
        {
            OLink p = M.chead[i];
            while (NULL != p)
            {
                printf("%d\t%d\t%d\n", p->i, p->j, p->e);
                p = p->down;
            }
        }
    }
}
