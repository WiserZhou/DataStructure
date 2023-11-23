#include <iostream>
#include <string>
using namespace std;
class Building;
class LaoWang
{
public:
    LaoWang();
    void visit();
    Building *building;

private:
};
class Building
{
    friend class LaoWang;

public:
    Building();
    string m_SittingRoom;

private:
    string m_BedRoom;
};
Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}
LaoWang::LaoWang()
{
    building = new Building;
}
void LaoWang::visit()
{
    cout << building->m_SittingRoom << endl;
    cout << building->m_BedRoom << endl;
}
void test()
{
    LaoWang lw;
    lw.visit();
}
int main()
{
    test();
    return 0;
}
