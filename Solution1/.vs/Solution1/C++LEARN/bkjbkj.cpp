#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    string name;
    char gender;
    int age;
    string department;
};

int main() {
    cout << "请输入学生个数：";
    int count;
    cin >> count;

    // 创建一个动态数组来存储所有学生
    Student* students = new Student[count];

    for (int i = 0; i < count; i++) {
        cout << "请输入第 " << i+1 << " 个学生的信息（姓名-性别-年龄-院系）：" << endl;
        cin >> students[i].name >> students[i].gender >> students[i].age >> students[i].department;
    }

    // 将学生信息写入文件
    ofstream outFile("students.txt");
    for (int i = 0; i < count; i++) {
        outFile << students[i].name << " " << students[i].gender << " " << students[i].age << " " << students[i].department << endl;
    }
    outFile.close();

    // 释放内存
    delete[] students;

    return 0;
}
