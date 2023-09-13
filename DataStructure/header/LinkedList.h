#include <iostream>
using namespace std;
#define LIST_INIT_SIZE 100
#define OVERFLOW 1
#define ERROR 0
#define LIST_INCREMENT 10
#define OK 1
#define TRUE 1
#define FALSE 0
#define NONE 0
typedef int ElemType;
typedef int Status;
typedef int Position;
struct Node
{
    ElemType value;
    Node *next;
    Node *prior;
    Node(int num) : value(num), next(nullptr){};
    Node(){};
};
class LinkList
{
private:
    Node *head, *end;
    int length;
    Node *createNode();
    void linkNode(Node *a, Node *b);
    void linkTriNode(Node *a, Node *b, Node *c);

public:
    LinkList();
    bool empty();
    int getLen();
    Node *getPrior(Node *p);
    Node *getNext(Node *p);
    Node *getPosition(int i);
    Node *getHeadPtr();
    Node *getEndPtr();
    Node *getFirst();
    Node *getLast();
    ElemType getValue(Node *p);


    Status setValue(Node *p, ElemType e);

    Status initList();
    Status initListWithValue(ElemType e);

    Status freeNodeByPtr(Node *p);
    Status freeNodeByIndex(int i);
    Status destroyList();
    Status clearList();
    Status deleteHead();
    Status deleteEnd();
    Status removeByValue(ElemType e);
    Status removeByIndex(int i);
    Status discard(Node *p);

    Status insertHead(ElemType e);
    Status insertEnd(ElemType e);
    Status insertBefore(Node *p, Node *q);
    Status insertAfter(Node *p, Node *q);

    Status changeNode(Node *cur_p, Node *fut_p);
    void changeAfter(Node *p);
    void changeBefore(Node *p);

    Node *searchNodeByValue(ElemType e);
    Node *searchNodeByIndex(int i);

    bool isEnd(Node *p);
    bool isHead(Node *p);

    Position locateElem(ElemType e);
    Status traverse(Status (*visit)(ElemType &e));
    Status static mergeList(LinkList La, LinkList Lb, LinkList &Lc, Status (*compare)(ElemType, ElemType));
    void display();
};
Status LinkList::mergeList(LinkList La, LinkList Lb, LinkList &Lc, Status (*compare)(ElemType, ElemType))
{
    if (!Lc.initList())
        return ERROR;
    Node *pa = La.getFirst();
    Node *pb = La.getFirst();
    while (!La.isEnd(pa) && !Lb.isEnd(pb))
    {
        ElemType a = La.getValue(pa);
        ElemType b = Lb.getValue(pb);
        if (compare(a, b))
            Lc.insertEnd(a);
        else
            Lc.insertEnd(b);
        pa = La.getNext(pa);
        pb = Lb.getNext(pb);
    }
    while (!La.isEnd(pa))
    {
        Lc.insertEnd(La.getValue(pa));
        pa = La.getNext(pa);
    }
    while (!Lb.isEnd(pb))
    {
        Lc.insertEnd(Lb.getValue(pb));
        pb = Lb.getNext(pb);
    }
    return OK;
}
bool LinkList::isEnd(Node *p)
{
    if (p == end)
        return true;
    else
        return false;
}
bool LinkList::isHead(Node *p)
{
    if (p == head)
        return true;
    else
        return false;
}
Node *LinkList::getFirst()
{
    return head->next;
}
Node *LinkList::getLast()
{
    return end->prior;
}

ElemType LinkList::getValue(Node *p)
{
    if (p != nullptr)
        return p->value;
    else
        return NONE;
}
Status LinkList::traverse(Status (*visit)(ElemType &e))
{
    Node *p = head->next;
    for (int i = 0; p != end; i++)
    {
        (visit)(p->value);
        p = p->next;
    }
    return OK;
}
Position LinkList::locateElem(ElemType e)
{
    Node *p = head->next;
    for (int i = 0; p != end; i++)
    {
        if (p->value == e)
        {
            return i;
        }
        p = p->next;
    }
    return -1;
}
Node *LinkList::getPosition(int i)
{
    Node *p = head;
    for (int j = 0; j < i; j++)
    {
        if (p->next == head)
            return nullptr;
        p = p->next;
    }
    return p->next;
}
Node *LinkList::getPrior(Node *p)
{
    return p->prior;
}
Node *LinkList::getNext(Node *p)
{
    return p->next;
}
Status LinkList::insertBefore(Node *p, Node *q)
{
    linkTriNode(p->prior, q, p);
    return OK;
}
Status LinkList::insertAfter(Node *p, Node *q)
{
    linkTriNode(p, q, p->next);
    return OK;
}
Node *LinkList::getHeadPtr()
{
    Node *p = head;
    return p;
}
Node *LinkList::getEndPtr()
{
    Node *p = end;
    return p;
}
void LinkList::display()
{
    Node *p = head->next;
    int i = 0;
    while (p != end)
    {
        cout << "value[" << i << "]: " << p->value << endl;
        p = p->next;
        i++;
    }
    if (i == 0)
        cout << "empty" << endl;
    cout << "length:" << length << endl;
}
int LinkList::getLen()
{
    return length;
}
LinkList::LinkList()
{
    initList();
}
bool LinkList::empty()
{
    if (length == 0)
        return true;
    else
        return false;
}
Status LinkList::setValue(Node *p, ElemType e)
{
    p->value = e;
    return OK;
}
Status LinkList::discard(Node *p)
{
    linkNode(p->prior, p->next);
    p->next = nullptr;
    p->prior = nullptr;
    length--;
    return OK;
}
void LinkList::changeAfter(Node *p)
{
    if (p == nullptr)
        return;
    else if (p == head || p == end)
    {
        cout << "head or end ptr is not permitted for control!" << endl;
        return;
    }

    Node *a = p->next;
    discard(p);
    linkTriNode(a, p, a->next);
}
void LinkList::changeBefore(Node *p)
{
    if (p == nullptr)
        return;
    else if (p == head || p == end)
    {
        cout << "head or end ptr is not permitted for control!" << endl;
        return;
    }

    Node *a = p->prior;
    discard(p);
    linkTriNode(a->prior, p, a);
}

Status LinkList::changeNode(Node *cur_p, Node *fut_p)
{
    if (cur_p->next == fut_p)
    {
        discard(fut_p);
        insertBefore(cur_p, fut_p);
    }
    else if (fut_p->next == cur_p)
    {
        discard(cur_p);
        insertBefore(fut_p, cur_p);
    }
    else
    {
        Node *p = cur_p->next;
        discard(cur_p);
        insertBefore(fut_p, cur_p);
        discard(fut_p);
        insertBefore(p, fut_p);
    }
    return OK;
}

Node *LinkList::searchNodeByIndex(int i)
{
    Node *p = head;
    for (int j = 0; j < i; j++)
    {
        if (p != head)
            p = p->next;
        else
            return nullptr;
    }
    return p;
}
Node *LinkList::searchNodeByValue(ElemType e)
{
    Node *p = head;
    while (p->next != head)
    {
        if (p->value == e)
            return p;
    }
    return nullptr;
}
void LinkList::linkTriNode(Node *a, Node *b, Node *c)
{
    a->next = b;
    b->prior = a;
    b->next = c;
    c->prior = b;
    length++;
}
void LinkList::linkNode(Node *a, Node *b)
{
    a->next = b;
    b->prior = a;
}
Node *LinkList::createNode()
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (!p)
        exit(OVERFLOW);
    return p;
}
Status LinkList::initList()
{
    length = 0;
    head = createNode();
    end = createNode();
    linkNode(head, end);
    linkNode(end, head);
    return OK;
}
Status LinkList::initListWithValue(ElemType e)
{
    length = 1;
    head = createNode();
    end = createNode();
    Node *p = createNode();
    p->value = e;
    linkTriNode(head, p, end);
    linkNode(end, head);
    return OK;
}
Status LinkList::freeNodeByPtr(Node *p)
{
    length--;
    linkNode(p->prior, p->next);
    free(p);
    p = nullptr;
    return OK;
}
Status LinkList::freeNodeByIndex(int i)
{

    Node *p = head;
    for (int j = 0; j < i; j++)
    {
        p = p->next;
        if (p->next == nullptr)
            return ERROR;
    }
    freeNodeByPtr(p->next);
    return OK;
}
Status LinkList::destroyList()
{

    length = 0;
    Node *p = head;
    Node *q = p->next;

    while (p != end)
    {
        freeNodeByPtr(p);
        p = q;
        q = q->next;
    }
    free(p);
    p = nullptr;
    return OK;
}
Status LinkList::clearList()
{

    destroyList();
    initList();
    return OK;
}
Status LinkList::insertHead(ElemType e)
{

    Node *p = createNode();
    p->value = e;
    linkTriNode(head, p, head->next);
    return OK;
}
Status LinkList::insertEnd(ElemType e)
{
    Node *p = createNode();
    p->value = e;
    linkTriNode(end->prior, p, end);
    return OK;
}
Status LinkList::deleteHead()
{
    if (length == 0)
        return NONE;
    freeNodeByPtr(head->next);
    return OK;
}
Status LinkList::deleteEnd()
{
    if (length == 0)
        return NONE;
    freeNodeByPtr(end->prior);
    return OK;
}
Status LinkList::removeByValue(ElemType e)
{
    Node *p = searchNodeByValue(e);
    if (p != nullptr)
    {
        freeNodeByPtr(p);
        return OK;
    }
    else
        return NONE;
}
Status LinkList::removeByIndex(int i)
{
    Node *p = searchNodeByIndex(i);
    if (p != nullptr)
    {
        freeNodeByPtr(p);
        return OK;
    }
    else
        return NONE;
}