
#include "..\header\LinkedList.h"
#include "..\header\unity.h"
int main()
{
    LinkList list;
    list.insertHead(2);
    list.insertEnd(3);
    list.display();
    cout << list.getLen() << endl;
    cout << list.locateElem(3) << endl;
    list.display();
    cout << list.getLen() << endl;
    return 0;
}