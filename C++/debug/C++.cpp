#include <iostream>
using namespace std;
class ClassA
{
public:
    ClassA()
    {
        cout << "ClassA" << endl;
    }
    ClassA(int i)
    {

        cout << "ClassA" << i << endl;
    }
    ClassA(const ClassA &src)
    {
        cout << "ClassA copy" << endl;
    } // 拷贝构造函数
    ClassA &operator=(const ClassA &rhs)
    {
        cout << "call ClassA" << endl;
    }
    virtual ~ClassA()
    {
        cout << "DeleteClassA" << endl;
    }
    void hornet(int i = 7) const
    {
        cout << "hornet ClassA" << i << endl;
    }
};
class ClassB : public ClassA
{
public:
    ClassB() : ClassA(1)
    {
        cout << "ClassB" << endl;
    }
    ClassB &operator=(const ClassB &rhs)
    {
        cout << "call ClassB" << endl;
    }
    virtual ~ClassB()
    {
        cout << "Delete ClassB" << endl;
    }
    void hornet(int i = 9) const
    {
        cout << "hornet ClassB" << i << endl;
    }
};
void find(const ClassA &inKlep)
{
    ClassA theClassA;
    inKlep.hornet(2);
}
int main()
{
    ClassB deri;
    cout << endl;

    ClassA base = deri; // 程序将此自动改写为：ClassA base(deri)，使用拷贝构造函数进行构造
    // ClassA base;
    // base = deri;//这么写的话，表明base初始化的时候调用了空参构造，然后再进行重载赋值号赋值

    // 如果您没有为类MyClass重载赋值运算符（operator=），则编译器会自动生成一个默认的赋值运算符，用于将一个对象的数据
    // 成员的值赋值给另一个同类型对象的数据成员。如果在语句obj2 = obj1;中，使用了这个默认的赋值运算符，则会按照以下方式进行操作：

    // 将obj1的数据成员的值分别赋值给obj2相应的数据成员；
    // 如果obj2原来已经有存储空间，则释放掉旧的存储空间（防止内存泄漏）；
    // 分配一块新的存储空间，并将obj1的数据成员的值复制到这个新的存储空间中。
    // 这些操作可以保证obj2与obj1数据内容相同，但它们是两个不同的对象，它们的地址也是不同的。

    // 需要注意的是，默认生成的赋值运算符可能不适合所有的情况，特别是当类中存在指针等动态分配内存的数据成员时，需要谨慎考
    // 虑是否需要自定义赋值运算符以避免出现浅拷贝等问题。
    cout << endl;
    find(deri);
    cout << "Done!" << endl;
    return 0;
}
// ClassA1 // ClassB的默认构造里面调用了ClassA的参数构造
// ClassB  //ClassB的空参构造

// ClassA copy  //ClassA 的拷贝构造函数调用

// ClassA   //find函数内部的构造
// hornet ClassA2 //由于参数是ClassA类，所以只能调用属于父类的函数
// DeleteClassA//find内部的定义的临时类析构
// Done!
// DeleteClassA //程序终止，删除base
// Delete ClassB//删除deri的子类
// DeleteClassA //删除deri的父类，这表明先对后定义的对象进行析构，倒着进行，进行的时候，先调用子类的析构

// 出栈（pop）和入栈（push）是指在栈数据结构中进行元素的添加和删除操作。

// 在栈的数据结构中，元素的插入和删除都只能从一端进行，这个端点被称之为“栈顶”。当一个元素被插入到栈中时，它就被推入到栈顶，这个过程叫做“入栈”操作；
// 当一个元素从栈中被移除时，它就从栈顶弹出，这个过程叫做“出栈”操作。

// 所以，栈的规则可以总结如下：

// 元素的插入和删除只能从栈顶进行；
// 最后插入的元素最先被删除，这就是所谓的“后进先出”（Last-In-First-Out，LIFO）原则；
// 栈顶指针（top）表示栈顶的位置，当栈为空时，top 的值为 -1；
// 当栈中有 n 个元素时，栈顶的位置是 n-1。
// 需要注意的是，在进行出栈操作时，必须确保栈不为空，否则会产生“栈下溢（stack underflow）”错误；而在进行入栈操作时，必须确保栈未满，否则会产生
// “栈上溢（stack overflow）”错误。

// 栈是一种后进先出（LIFO）的数据结构，通常用来存储函数调用时的临时变量、局部变量、函数返回地址以及函数调用上下文等信息。当一个函数被调用
// 时，它的参数和局部变量会被压入栈中；当函数执行完毕时，这些变量从栈中弹出，控制权返回给上层函数。

// 除了函数调用时的临时变量和上下文信息之外，栈还可以用来实现表达式求值、字符串反转、括号匹配等问题。在表达式求值时，操作数和操作符都可以
// 被压入栈中，计算结果也可以被压入栈中。在字符串反转时，每个字符可以被压入栈中，然后依次弹出组成新的字符串。在括号匹配时，左括号可以被压入
// 栈中，遇到右括号时弹出栈顶元素，如果弹出的不是相应的左括号，则表示匹配失败。

// 总之，栈是一种非常有用的数据结构，可以用来解决很多实际问题。

// 堆（Heap）是一种特殊的树形数据结构，其中每个节点都有一个值，并且每个节点的子节点都遵循一定的规则。在堆中，通常将父节点的值设置为大于或小于它
// 的所有子节点的值，这样就可以保证堆的性质。

// 具体来说，如果父节点的值大于或等于子节点的值，则称之为“最大堆”；如果父节点的值小于或等于子节点的值，则称之为“最小堆”。最大堆常常用于实现优先
// 队列，而最小堆常用于排序算法中，如堆排序。

// 堆可以通过数组来实现，其中数组下标 i 的左子节点下标为 2i+1，右子节点下标为 2i+2，父节点下标为 (i-1)/2。这种方式称为“数组表示法”。

// 值得注意的是，堆并不是一棵严格意义上的二叉树，因为它只需要满足父节点与子节点的大小关系即可，而不需要保证所有的节点都拥有两个子节点。

// 在计算机科学中，堆（Heap）通常指的是动态内存分配时，程序运行时动态申请的内存空间，这种堆称为“堆内存”（Heap Memory）。堆内存的使
// 用方式与栈（Stack）不同，因为在栈中，变量的生命周期由它们的作用域决定，当变量超出作用域时，该变量所占用的栈空间会被自动回收；而在堆
// 中，程序员需要手动申请和释放内存，否则可能会导致内存泄漏等问题。

// 在堆内存中，可以存储各种类型的数据，如整数、浮点数、字符串、数组、结构体、对象等。堆内存的大小通常受制于操作系统和硬件限制，如果申
// 请的内存超过了可用的物理内存，则可能会导致“内存溢出”错误。

// 在实际编程中，堆内存通常用于动态存储数据结构，如链表、二叉树、图等，以及大型数组、缓存等。此外，堆内存还常常用于实现动态链
// 接库（Dynamic Link Library，DLL）和插件等功能。

// 全局变量是在程序运行期间占用的静态内存，通常存储在程序的数据段（Data Segment）中。数据段是一个固定大小的内存块，在程序加载时就会
// 被分配好，并且包含了全局变量和静态变量等。

// 与堆内存和栈内存不同，数据段的大小在编译时就已经确定了，因此，程序在运行期间无法动态地增加或减少数据段的大小。由于数据段是在程序加
// 载时就被分配好的，因此，全局变量的生命周期与程序的运行周期一致，只有当程序退出时才会被自动释放。

// 需要注意的是，如果全局变量没有被显式地初始化，则它们会被自动初始化为 0 或 NULL 等默认值，这取决于它们的类型。例如，全局整型变量在没
// 有被初始化时会被自动初始化为 0。如果想要改变全局变量的初始值，可以在定义时进行赋值操作。

// 栈 ----局部变量
// 堆 ----动态储存
// 数据段-----全局变量
#include <iostream>
using namespace std;

class A
{
private:
    string s;

public:
    A(string ss = "")
    {
        s = ss;
    }
    void input()
    {
        cout << "input string:";
        cin >> s;
    }
    void output() const
    {
        cout << "the string is:" << s << endl;
    }
    A(const A &a)
    {
        cout << "------>" << a.s << "<--------" << endl;
        s = a.s;
    }
    A &operator-(A &a)
    {
        static A temp;
        // 静态成员不允许被引用
        string s1 = a.s;
        string::size_type n = 0;
        // string::size_type 是 C++ 标准库中 string 类型的无符号整数类型。它通常被用来
        // 表示字符串对象的大小或索引。size_type 被定义为 typedef，可以根据实现而定，在
        // 某些平台上可能是 unsigned int 或 unsigned long。
        // 使用 string::size_type 定义变量时，可以保证该变量足够大，以容纳字符串对象的
        // 大小。同时，也可以避免在不同平台上使用不同类型而带来的问题。
        while (true)
        {
            string::size_type find_position = s.find(s1, n);
            //  string 对象的 find() 函数是用来查找特定子字符串在当前字符串中第一次出
            //  现的位置。该函数有多种重载形式。
            //  该函数接受两个参数：要查找的子字符串 str 和搜索的起始位置 pos，默认值为
            //   0。如果找到了该子字符串，则返回它在当前字符串中第一次出现的位置（位置从 0
            //   开始计数），否则返回 string::npos，表示未找到。
            // 在这个例子中从索引n开始搜索与s1相同的字符串
            if (find_position != string::npos)

            // std::string::npos 是一个类常量，它是 std::string 类中的一个静态成员。
            // npos 表示“无效位置”或“无穷大位置”，在字符串操作中通常用于表示超出有效范围
            // 的指针位置。static const size_type npos = -1;

            {
                s.erase(find_position, s1.size());
                // std::string 是一个表示字符串的类，它提供了 erase() 函数用于删除字符串中特定
                // 位置的字符。
                // 删除单个字符：void erase(size_t pos = 0, size_t len = npos);

                // 参数 pos 表示要删除的字符在字符串中的位置。
                // 参数 len 表示要删除的字符的数量，默认值为 npos，即删除从 pos 开始到字符串末
                // 尾的所有字符。
                // 这个写法就是从搜索到的位置开始删除所搜索字符串的长度，不包含终止符
                // cout << "*" << s << endl;
            }
            else
                break;
        }
        temp.s = s;
        return temp;
    }
    // 在 C++ 中，当一个函数返回一个临时对象时，这个对象的生命周期仅限于表达式的执行过程中，即直到表达式结束为止。因此，对于这个临时对象而言，我们
    // 不能够持有它的引用或指针，并且也不能修改它的值，因为一旦表达式结束，这个对象就会被销毁，从而导致悬垂指针或引用无法访问的问题。

    // 在上面的代码中，函数operator-(A a)返回的是一个临时对象temp，这个对象的生命周期仅限于表达式s1 - s2的执行过程中。因此，如果我们尝试使用引用
    // 或指针来修改这个对象的值，那么就会存在悬垂指针或引用的风险，导致程序出现未定义的行为。

    // 为了避免这种情况的发生，我们应该尽可能地保证函数返回值的不可变性，即使用常量限定符(const)来修饰它的返回类型和参数类型，从而避免对其进行非法
    // 修改操作。在上面的代码中，我们通过将函数operator-(A a)声明为const成员函数，并将返回值和参数类型均声明为const引用，从而保证了函数返回值的不可变性。

    // 总之，在 C++ 中，对于临时对象的使用时需要格外小心，必须确保不会出现悬垂指针或引用，并且尽可能地保证它们的不可变性，从而避免程序出现未定义的行为。
};
ostream &operator<<(ostream &os, const A &a)
{
    a.output();
    return os;
}
int main()
{
    A s1("this Is a book!");
    A s2("Is");
    cout << "-------+" << endl;
    cout << s1;
    cout << s2;
    cout << "----------+" << endl;
    cout << s1 - s2;
    return 0;
}

#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include <cctype>
using namespace std;
class Square
{
private:
    int n;
    string s;

public:
    Square() {}

    int str2num(string s)
    {
        int temp;
        stringstream ss;
        // stringstream是C++中的一个类，它允许将字符串作为流来处理，可以方便地对字
        // 符串进行输入输出操作。stringstream通常用于字符串解析和格式化输出。
        // 使用stringstream需要包含头文件<sstream>。
        ss.str(s);
        // 或者写ss<<s也可
        ss >> temp;

        // 可以类比标准输入流cin>>s，是一个意思
        return temp;
    }
    bool input() // 判断是不是数字
    {
        bool flag = true;
        cout << "input a number:";
        cin >> s;
        for (int i = 0; i < s.size(); ++i)
        {
            if (isdigit(s[i]))
                continue;
            else
            {
                cout << "输入的不是数字，请重新输入!" << endl;
                flag = false;
                break;
            }
        }
        return flag;
    }
    void cal()
    {
        while (true)
        {
            if (input() == true)
            {
                n = str2num(s);
                cout << "square:" << n * n << endl;
                break;
            }
        }
    }
};

int main()
{
    Square s;
    s.cal();
    return 0;
}

#include <iostream>
using namespace std;
int add(int a, int b)
{
    return a + b;
}
double add(double m, double n)
{
    return m + n;
}
// 函数重载只要函数存在相同的名字和不同的参数列表即可，返回值根据实际情况变化
int main()
{
    cout << add(1, 2) << endl;
    cout << add(1.2, 2.3) << endl;
    return 0;
}

#include <iostream>
using namespace std;

#include <string>
#include <cstring>

class StringPlus
{
    char *p;

public:
    StringPlus(const char *s)
    {
        if (s)
        {
            p = new char[strlen(s) + 1];
            // 为p开辟空间
            strcpy(p, s);
        }
        else
            p = NULL;
        // 这是因为 strlen() 函数要求传入的参数是一个指向以 null 结尾的字符数组的指针。
        // 如果传入 NULL 指针或非法指针会导致程序崩溃或出现错误结果。
        // 在这种情况下，如果 s 是 NULL，则分配给 p 的内存大小是不确定的，由于无法获得
        // s 的长度，因此可能会发生缓冲区溢出或其他意外情况，这可能会导致程序崩溃或数据损坏。

        // 归根到底就是因为strlen这个函数并不安全
    }
    StringPlus(const StringPlus &s)
    {
        if (s.p != NULL)
        {
            p = new char[strlen(s.p) + 1];
            strcpy(p, s.p);
        }
        // 未定义行为（Undefined Behavior）指的是程序在执行过程中遇到了某些未经定义的情况，导致了不可预测的结果。这些未经定义的情况可能包括使用野
        // 指针、数组越界、访问已释放的内存等。

        // 在C++语言中，对于一些操作，标准并没有规定具体的实现方式或者行为。当程序员违反了这些规定时，就会导致未定义行为。对于发生了未定义行为的程
        // 序，编译器和运行时库可以做出任何行为，包括崩溃、输出异常结果、表现正常等等，具体取决于实现方式和环境。

        // 在我们的例子中，如果delete[]操作符被调用时指针p为空指针，那么就会导致未定义行为。由于标准库没有规定空指针作为delete[]操作符的参数时应
        // 该如何处理，因此程序的行为是不可预测的。这种情况下，程序可能会崩溃、输出异常结果，也有可能表现为正常运行但实际上并没有释放任何内存。因此
        // ，我们必须避免将空指针作为delete[]操作符的参数来保证程序的正确性。
        else
            p = NULL;
    }
    // 复制构造函数
    ~StringPlus()
    {
        if (p)
            delete[] p;

        // 在析构函数中使用 if (p) 来判断成员变量 p 是否为 NULL 的目的是确保只释放已经分
        // 配了内存的对象。如果 p 是 NULL，则说明该对象没有分配内存，也就不需要进行内存
        // 释放操作。
        // 如果在没有对 p 进行判空操作的情况下，直接执行 delete[] p; 将会导致未定义行为
        // ，因为 delete[] 操作符将试图释放一个空指针所指向的内存块，这可能会导致程序崩
        // 溃或出现其他意外结果。
        // 因此，在对 p 进行 delete[] 之前，应该始终先确保它不是 NULL。
        // 归根到底还是因为delete并不安全
    }
    void Copy(char *s)
    {
        if (s != NULL)
        {
            if (p != NULL)
            {
                delete[] p;
            }
            p = new char[strlen(s) + 1];
            strcpy(p, s);
        }
        else if (p != NULL)
        {
            delete[] p;
            p = NULL;
        }
    }
    // delete 和 delete[] 都是用于在程序运行时释放动态申请的内存的操作符。它们之
    // 间的主要区别在于释放的内存块的类型和数量：
    // delete 用于释放单个对象所占用的内存空间，它只能释放由 new 运算符申请的单个
    // 对象的内存空间。
    // delete[] 用于释放数组所占用的内存空间，它可以释放由 new[] 运算符申请的数组
    // 对象的内存空间。
    // 在实现上，delete[] 会先通过指针所指向的内存块中存储的元素数量信息计算出需要
    // 释放的内存块的大小，再根据这个大小来释放内存；而 delete 则只直接释放指定的内存
    // 块。
    // 如果使用 delete 来释放由 new[] 分配的内存，则可能导致部分内存没有被完全释放，
    // 从而造成内存泄漏或其他问题。同样地，如果使用 delete[] 来释放由 new 分配的内存
    // ，则也可能会导致未定义行为。因此，应该根据动态申请内存的方式来选择使用 delete
    // 还是 delete[] 进行内存释放。
    StringPlus &operator=(const StringPlus &s)
    {
        if (s.p != NULL)
        {
            if (p != NULL)
                delete[] p;
            p = new char[strlen(s.p) + 1];
            strcpy(p, s.p);
        }
        else if (p != NULL)
        {
            delete[] p;
            p = NULL;
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, StringPlus &s)
    {
        out << s.p;
        return out;
    }
    // 这个函数的返回值也是返回给调用它的代码。与之前的例子相比，唯一不同的是，这里将字符串内容输出到了传递进来的输出流对
    // 象 out 中，而不是直接输出到标准输出流 cout 中。

    // 当我们像下面这样使用cout输出StringPlus对象时：

    // StringPlus s("Hello");
    // cout << s;
    // 实际上会被转换为如下形式：

    // StringPlus s("Hello");
    // operator<<(cout, s);
    // 因此，这个函数的返回值将会返回给cout对象，即输出流。这样可以支持链式使用 cout，例如：

    // cout << s1 << s2 << s3;
    // 在这种情况下，每个 operator<< 函数都返回 cout 对象本身，以便可以继续使用它输出后续内容。

    // 返回给了cout（即输出流对象）是因为在C++中，重载输出运算符<<时通常都会将左侧的参数设置为输出流对象（如ostream&），以支持链式输出。

    // 在使用链式输出时，每个<<操作符返回左侧的输出流对象，这样就可以继续在其上进行下一个输出操作。例如：

    // cout << s1 << s2;
    // 在这个例子中，第一个<<操作符将字符串s1写入到cout中，并返回cout本身，因此可以使用第二个<<操作符将字符串s2继续写入到cout中。因此，在这里
    // 将输出流对象out作为函数参数传递进来，并在函数中进行操作后，需要将其返回以支持链式输出。
};
int main()
{
    char w1[200] = "sss", w2[100] = "aaa";

    while (true)
    {
        StringPlus s1(w1), s2 = s1; // s2=s1是一个复制构造函数，构造函数只存在于定义的时候，这与下面的s1=s3不同，就算是=也不是重载运算符
        StringPlus s3(NULL);
        s3.Copy(w1);
        cout << s1 << "," << s2 << "," << s3 << endl;
        s2 = w2;
        // 这个过程是先把w2调用构造函数变成一个对象，然后再将这个临时对象重载=给s2，然后再把临时产生的对象进行析构
        // 这个w2变成对象是调用了第一个构造函数的隐式转换，能转换的前提是有这个函数的定义
        s3 = s2;
        s1 = s3;
        cout << s1 << "," << s2 << "," << s3 << endl;
        break;
    }
}
// 注意构造函数只能在声明对象的时候使用（非必要不考虑隐式）

// 在 C++ 中，有一些运算符是不可以被重载的。其中包括：
// "."：成员访问运算符
// "*"：成员指针访问运算符
// "::"：作用域解析运算符
// "?："：条件运算符（三元运算符）
// sizeof：长度运算符
// typeid：类型识别运算符
// 这些运算符都是具有特殊含义的，并且不能被程序员重载。

// typeid 是 C++ 中的一个运算符，用于获取一个表达式的类型信息。它可以接受一个表达
// 式，返回一个表示该表达式类型的 std::type_info 对象。
// typeid 运算符的使用方式为 typeid(expression)，其中 expression 可以是任何表
// 达式，包括变量、函数调用、指针等等。
// std::type_info 类型的对象可以使用 type_info 头文件中的成员函数获取类型名称、
// 比较类型是否相同等信息，这些函数包括：
// name()：返回类型的 C 风格字符串名称。
// operator==() 和 operator!=()：比较两个类型是否相等。
// 其他成员函数，如 before()、hash_code() 等等。
// typeid 运算符通常用于在运行时确定一个对象的类型，从而进行类型安全的操作。

// 下面是一个使用 typeid 运算符的例子：

// c++
// #include <iostream>
// #include <typeinfo>

// int main() {
//     int i = 10;
//     double d = 3.14;

//     const std::type_info& ti1 = typeid(i);
//     const std::type_info& ti2 = typeid(d);

//     if (ti1 == ti2) {
//         std::cout << "i and d are of the same type." << std::endl;
//     } else {
//         std::cout << "i and d are of different types." << std::endl;
//     }

//     std::cout << "Type of i is " << ti1.name() << std::endl;
//     std::cout << "Type of d is " << ti2.name() << std::endl;

//     return 0;
// }
// 运行结果为：

// i and d are of different types.
// Type of i is int
// Type of d is double
// 在这个例子中，我们定义了两个变量 i 和 d，并使用 typeid 运算符获取
// 它们的类型信息。由于 i 和 d 的类型不同，所以第一个条件不满足，程序输出
// 了 "i and d are of different types."。然后我们使用 name() 成员函数获
// 取了变量的类型名称，并将其输出到屏幕上。

// type_info 是 C++ 标准库中的一个类，它定义了一个抽象基类，用于存储类型信息。
// 它包含一个 name() 成员函数，可以返回当前类型的名称。
// 当我们使用 typeid 运算符获取表达式的类型信息时，运算符返回的是一个
//  const std::type_info& 类型的值，该值代表了表达式所属的类型。我们可以使
//  用 name() 成员函数来获取这个类型的名称。
// 要使用 type_info 类型，通常需要包含头文件 <typeinfo>。需要注意的是，由于
// type_info 是一个抽象基类，不能直接实例化，只能通过其派生类来进行操作。

// C++ 的拷贝构造函数是一种特殊的构造函数，用于在创建对象时从另一个同类型的对
// 象中复制其值和属性。拷贝构造函数通常用于以下三种情况：

// 对象作为函数参数时以值传递方式传递：当对象作为函数参数时，需要将原始对象的值
// 复制到一个新的临时对象中，并将该临时对象作为参数传递给函数。

// 从一个对象初始化另一个对象：当使用类似于 MyClass obj2 = obj1 的语句初始化
// 一个新的对象时，需要调用拷贝构造函数来将原始对象的值复制到新对象中。

// 当函数返回一个对象时：当函数返回一个对象时，需要将对象的值复制到一个新的临时
// 对象中，并将该临时对象作为函数的返回值。

// 拷贝构造函数的定义如下：

// c++
// class MyClass {
// public:
//     // 拷贝构造函数
//     MyClass(const MyClass& other) {
//         // 执行深拷贝操作
//     }
// };

// 需要注意的是，如果类中包含指针等资源成员，则默认的拷贝构造函数只能进行浅拷贝
// ，即将指针的值复制到新对象中，而不是将指针所指向的实际对象进行复制。这可能会导
// 致多个对象共享同一块内存空间，进而引发内存泄漏和程序错误。因此，如果类中包含指
// 针等资源成员，则需要手动实现拷贝构造函数来进行深拷贝操作。

// 另外，需要注意的是，在使用拷贝构造函数时，应该避免无限递归，即在拷贝构造函数中
// 调用自身会导致无限循环调用。例如：

// c++
// class MyClass {
// public:
//     // 错误的拷贝构造函数定义
//     MyClass(const MyClass& other) {
//         MyClass temp(other); // 无限递归调用拷贝构造函数
//     }
// };
// 最后，需要注意的是，在 C++11 中，可以使用移动构造函数（Move Constructor）
// 来实现更高效的对象复制和传递。移动构造函数将对象的资源所有权从一个对象转移到另
// 一个新对象，避免了不必要的内存拷贝和分配。
// http://c.biancheng.net/view/151.html
// 非常详细，非常深刻，建议看完

// C++ 中的 inline 关键字是一种对编译器的提示，用于请求将函数代码直接插入到调
// 用该函数的地方，而不是通过函数调用的方式执行。这样可以避免函数调用带来的额外
// 开销，从而提高程序的运行效率。

// 需要注意的是，编译器并不一定会遵循 inline 的请求，具体是否进行内联取决于编译
// 器的实现。通常情况下，编译器只会在函数比较小且被频繁调用的情况下才会进行内联优
// 化。

// 示例代码：

// cpp
// inline int add(int a, int b) {
//     return a + b;
// }

// int main() {
//     int x = 1, y = 2;
//     int z = add(x, y);  // 函数调用被替换为直接插入函数体
//     return 0;
// }
// 需要注意的是，使用 inline 关键字声明的函数必须定义在头文件中或者在每个
// 使用该函数的源文件中都要有定义，否则可能会导致链接错误。

// 个人评价：实际上inline就算你不写编译器也可以帮你写上，所以它对于程序员来说可以不写
// 写上也只是声明的的作用，没有实际作用

// 在 C++ 中，虚函数是为了实现运行时的多态性而设计的。通过在基类中声明虚函数，在
// 派生类中对其进行重写，可以实现对不同类型对象的统一操作。

// 具体来说，当通过基类指针或引用调用虚函数时，程序会根据实际指向的对象类型来决定
// 调用哪个版本的虚函数，从而实现动态绑定。

// 示例代码：

// cpp
// class Shape {
// public:
//     virtual double area() const { return 0.0; } // 声明一个虚函数
// };

// class Rectangle : public Shape {
// public:
//     Rectangle(double w, double h) : width(w), height(h) {}
//     double area() const override { // 重写虚函数
//         return width * height;
//     }
// private:
//     double width;
//     double height;
// };

// class Circle : public Shape {
// public:
//     Circle(double r) : radius(r) {}
//     double area() const override { // 重写虚函数
//         return 3.14159 * radius * radius;
//     }
// private:
//     double radius;
// };

// int main() {
//     Shape* shape1 = new Rectangle(3.0, 4.0); // 基类指针指向派生类对象
//     Shape* shape2 = new Circle(2.0); // 基类指针指向派生类对象
//     double a1 = shape1->area(); // 能正确调用 Rectangle 中的 area 函数
//     double a2 = shape2->area(); // 能正确调用 Circle 中的 area 函数
//     delete shape1;
//     delete shape2;
//     return 0;
// }
// 需要注意的是，虚函数通过在运行时进行动态绑定实现多态性，但这也带来了一些性
// 能上的损耗。因此，在设计类的时候需要权衡使用虚函数的利弊，避免过度使用导致程
// 序效率低下。

// 在 C++ 中，构造函数是一种特殊的成员函数，用于创建对象并初始化其成员变量。
// 构造函数没有返回类型，因此不能有显式的返回值。
// 在构造函数执行过程中，如果需要结束构造函数并返回，可以抛出异常或者调用
// exit() 函数等方式来实现，但这并不是一个好的编程习惯，因为会导致对象无法正确
// 地创建和初始化。
// 示例代码：

// cpp
// class MyClass {
// public:
//     MyClass(int x) {
//         if (x < 0) {
//             throw "x should not be negative"; // 抛出异常
//         }
//         value = x;
//     }
// private:
//     int value;
// };

// int main() {
//     try {
//         MyClass obj1(5); // 正常调用构造函数
//         MyClass obj2(-1); // 抛出异常，对象未能正确创建和初始化
//     } catch (const char* msg) {
//         cout << "Exception: " << msg << endl;
//     }
//     return 0;
// }

// 需要注意的是，虽然构造函数不能显式返回值，但它们可以隐式地返回一个指向自
// 身的指针（即 this 指针），以便支持链式调用。比如，在某些情况下我们可能需
// 要返回 *this 来实现链式赋值操作。
// 这句话主要是在讲述 C++ 中的构造函数可以隐式地返回一个指向自身的指针，即 this 指针，以支持链式调用。这也就是为什么我们经常会在
// 一些 C++ 类的方法中看到返回类型为该类对象的引用（如 className&）的语法。

// 比如，在某些情况下，我们可能需要实现链式赋值操作，即在一条语句中连续赋值多个属性或者方法，例如：

// obj.setValue(42).setName("foo").setFlag(true);
// 这里的 setValue、setName 和 setFlag 都是该类的成员方法，它们都返回一个指向该类对象的引用。因此，它们可以被连接起来形成链式调
// 用。在实现这些方法时，通常会在方法内部返回 *this，即指向当前对象的引用，以保证链式调用能够顺利进行。

// 拷贝构造函数是一种特殊的构造函数，它用于创建一个新对象并将其初始化为另一个同
// 类型对象的副本。在 C++ 中，拷贝构造函数通常采用引用传递参数的方式来接收待复
// 制的对象。
// 使用引用传递可以避免浪费时间和空间来复制一个完整的对象，并且可以保证高效的拷
// 贝操作，同时也会避免由于传值调用而产生的不必要的数据丢失或修改的问题。

// 示例代码：

// cpp
// class MyClass {
// public:
//     MyClass(int x) : value(x) {} // 普通构造函数
//     MyClass(const MyClass& other) : value(other.value) {} // 拷贝构造函数
// private:
//     int value;
// };

// int main() {
//     MyClass obj1(5); // 调用普通构造函数创建对象
//     MyClass obj2(obj1); // 调用拷贝构造函数创建对象
//     return 0;
// }
// 需要注意的是，如果未定义自己的拷贝构造函数，则编译器会自动生成一个默认的拷
// 贝构造函数，该函数采用值传递的方式来接收参数。只有在对象中存在动态资源分配
// （如堆内存）或者需要进行深度拷贝时才需要定义自己的拷贝构造函数。

// 动态绑定（Dynamic binding）是指在运行时确定对象实例的方法调用而不是
// 在编译时确定。当一个对象被创建后，它的类型是确定的，但它所引用的方法却是
// 不确定的，因为子类可以重写父类的方法。在动态绑定中，方法调用的分派是基于对
// 象的实际类型进行的，而不是基于变量的声明类型。
// 在使用动态绑定时，编译器并不知道具体调用哪个方法，而是等待运行时才能决定。
// 这种机制使得程序更加灵活和可扩展，因为它允许我们在运行时根据实际需要来决定调
// 用哪个方法，而不必预先确定每个对象将要调用哪些方法。
// 在面向对象编程中，动态绑定通常与多态性相关联。多态性是指同一操作作用于不同的
// 对象会产生不同的结果，因此在使用动态绑定时，我们可以通过向上转型或向下转型来
// 实现多态性，从而提高代码的可复用性和可读性。

// 假设我们有一个父类Animal和两个子类Dog和Cat，它们都有一个speak()方法。在
// 编译时，编译器只能确定Animal类型的变量可以调用speak()方法，但无法确定具
// 体调用哪个子类的方法，因为这取决于运行时实际创建的对象的类型。这就是动态绑定。

// 例如，假设我们有如下代码：

// Animal animal1 = new Dog();
// Animal animal2 = new Cat();
// animal1.speak();
// animal2.speak();

// 在运行时，animal1和animal2分别指向Dog和Cat类型的对象，因此调用speak()方法
// 时会分别调用Dog类和Cat类中重写的speak()方法，而不是Animal类中的speak()方法
// 。这是因为在运行时，程序会根据对象实际的类型来确定调用哪个方法，而不是根据变
// 量声明的类型来确定。这就是动态绑定的实现方式之一。

// 28.下列哪种赋值会产生编译错误（)
// A、将基类对象的地址赋值给基类指针
// B、将基类对象的地址赋值给派生类指针
// C、将派生类对象的地址赋值给基类指针
// D、将派生类对象的地址赋值给派生类指针
// 选项B，将基类对象的地址赋值给派生类指针会产生编译错误。

// 解析：

// A、将基类对象的地址赋值给基类指针是合法的操作，因为基类指针可以指向基类对象。
// C、将派生类对象的地址赋值给基类指针也是一种合法操作，但在使用基类指针访问新增的成员时需要进行类型转换。
// D、将派生类对象的地址赋值给派生类指针也是合法的操作，因为派生类指针可以指向派生类对象。

// 但是，将基类对象的地址赋值给派生类指针是不合法的操作。原因是派生类对象比基类对
// 象多了一些成员变量和函数，如果将基类对象的地址赋给派生类指针，那么这些新增的
// 成员就无法通过该指针访问到。而将基类指针转换为派生类指针也需要满足一定的条件
// ，如该指针所指向的对象必须是派生类对象，否则会导致未定义行为或程序崩溃。

#include <iostream>
using namespace std;

double division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    return (a / b);
}

int main()
{
    int x = 50;
    int y = 0;
    double z = 0;

    try
    {
        z = division(x, y);
        cout << z << endl;
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
    return 0;
}

// 这是一个使用 C++ 中异常处理机制的例子。该程序定义了一个函数 division，用于计算
// 两个整数的商，如果除数为 0，则抛出异常。在 main 函数中，程序通过调用 division
// 函数来进行计算，并使用 try 块捕获异常。如果发生异常，则程序将错误消息打印到标准
// 错误流 cerr 中。最后返回 0 表示程序正常结束。

// 需要注意的是，由于抛出的异常类型是 const char*，因此在 catch 块中使用的是字符
// 串字面值 "Division by zero condition!"。实际上，在编写实际应用程序时，更好的
// 做法是定义一个自定义异常类，并在抛出异常时使用该类的对象，这样可以提供更多的错误
// 信息和上下文。

// exception 是 C++ 标准库中定义的一个类，它用于表示异常。当程序运行过程中遇到错误
// 或不可预料的情况时，可以抛出一个 exception 类型的对象来表示发生了异常，并且可
// 以通过 try...catch 语句来捕获并处理这个异常。

// exception 类是一个基类，一般情况下应该定义一个派生类来表示具体的异常类型。例如
// ，可以定义一个 MyException 类，来表示自己应用程序中的特定异常。在抛出异常时，
// 应该使用 throw 语句并提供一个对应的异常对象（或者是它的子类对象）。

// 在 try...catch 语句中，可以使用 catch 关键字来捕获特定类型的异常。例如，如果
// 想要捕获 MyException 类型的异常，可以使用以下代码：

// cpp
// try {
//     // some code that may throw a MyException
// } catch (const MyException& e) {
//     // handle the exception
// }
// 总之，exception 提供了一种通用的方法来表示和处理异常，并且可以与其他标准库和用
// 户自定义类一起使用。

// 在C++中，异常处理是一种错误处理机制，它使程序能够在遇到无法处理的错误或异常情
// 况时，以一种有组织的方式进行控制流转移。异常处理通过抛出异常、捕获异常和处理异
// 常三个过程来实现。

// 抛出异常
// 当程序出现错误或异常状况时，可以使用throw语句来抛出一个异常对象。throw语句会立
// 即终止当前函数的执行，并将控制权转移到该函数的调用者处。

// 例如：

// void f(int x) {
//     if (x < 0) {
//         throw "Error: x is negative.";
//     }
//     // ...
// }
// 在这个例子中，如果x小于零，就会抛出一个字符串类型的异常对象。

// 捕获异常
// 在程序中捕获异常有两种方式：使用try-catch语句和使用noexcept关键字。

// try-catch语句的基本语法如下：

// try {
//     // 可能引发异常的代码块
// } catch (exceptionType1 e1) {
//     // 处理exceptionType1类型的异常
// } catch (exceptionType2 e2) {
//     // 处理exceptionType2类型的异常
// } catch (...) {
//     // 处理其他所有类型的异常
// }
// 其中，try块包含可能会引发异常的代码，catch块则用于捕获特定类型的异常，并给出
// 相应的处理方法。多个catch块可以连续出现，每个catch块可以捕获不同类型的异常。
// 如果所有catch块都无法处理该异常，程序会继续向上层调用者抛出异常。

// 例如：

// try {
//     f(x);
// } catch (const char* e) {
//     cout << "Caught exception: " << e << endl;
// }
// 在这个例子中，如果函数f()抛出了一个字符指针类型的异常对象，就会被catch块捕获
// 并输出异常信息。

// noexcept关键字用于指示某个函数是否可能引发异常，其基本语法如下：

// void f() noexcept;
// 其中，noexcept关键字后面可以跟一个表达式或省略号(...)，表示该函数是否可能引发
// 异常。如果函数声明了noexcept关键字，则编译器会对其进行优化，以提高程序的性能。

// 处理异常
// 当程序抛出异常时，它将控制权转移到最近的catch块，并执行其中的代码。catch块的处
// 理方法各不相同，可以根据实际情况来进行选择。通常，我们可以在catch块中记录日志
// 、恢复程序状态、重新抛出异常或者简单地提示用户异常信息等。

// 例如：

// try {
//     f(x);
// } catch (const char* e) {
//     cout << "Caught exception: " << e << endl;
//     // 记录日志
//     // 恢复程序状态
//     // 重新抛出异常
//     // 提示用户异常信息
// }
// 在这个例子中，如果函数f()抛出了一个字符指针类型的异常对象，就会被catch块捕获
// 并输出异常信息。我们可以在catch块中记录日志、恢复程序状态、重新抛出异常或者提
// 示用户异常信息等操作。

// 在 C++ 中，如果使用 new 操作符分配内存失败，则会引发 std::bad_alloc 异常。
// 这通常表示计算机的可用内存不足，或者已经耗尽了进程的可用内存。

// 可以通过在 new 表达式前添加异常处理代码来捕获这个异常并采取适当的措施来处理它。
// 例如，可以释放已分配的内存，或者向用户显示错误消息。

// 以下是一个示例代码片段，演示如何使用 try-catch 块来处理 new 操作符失败引发的异
// 常：

// try {
//     int* myArray = new int[1000000];
// }
// catch (std::bad_alloc& exc) {
//     // 内存分配失败，执行必要的清理操作
//     std::cerr << "Memory allocation failed: " << exc.what() << std::endl;
// }
// 在上述代码中，我们试图为一个包含 1000000 个整数的数组分配内存。如果内存分配失
// 败，则会引发 std::bad_alloc 异常，并且将控制流传递到 catch 块中，其中我们
// 可以执行必要的清理操作。在此处，我们只是向标准错误输出打印一条错误消息。

// 在 C++ 标准库中， std::bad_alloc 是一个类（class），它派生自 std::exception
// 。当内存分配失败时，会抛出这个类的对象作为异常。

// 该类提供了一些成员函数来访问异常信息，如 what() 函数用于返回描述异常原因的字符
// 串。您可以通过捕获 std::bad_alloc 类型的异常并调用其成员函数来获取有关内存分
// 配失败的详细信息。

// 引用静态类成员变量的方法：
// 可以用类名和作用域运算符
// 也可以用对象和成员运算符

// 在 C++ 中，引用本身就是一个指向内存中某个对象的别名，并不需要显示地进行解引用
// 操作。当使用引用时，编译器将自动为我们解引用引用所指向的对象。

// 例如，假设我们有一个 int 类型的变量 x，并创建了一个引用 ref 来引用它：

// int x = 42;
// int& ref = x;

// 在此处，ref 就是 x 的引用，它与 x 指向同一个对象。如果我们想要访问 x 中存储
// 的整数值，可以直接使用 ref 变量，而无需显式地对其进行解引用操作。例如：

// std::cout << "The value of x is: " << x << std::endl; // 输出 42
// std::cout << "The value of ref is: " << ref << std::endl; // 输出 42
// 在上述代码中，我们通过 std::cout 向控制台输出了 x 和 ref 变量的值。因为 ref
//  是 x 的引用，因此使用 ref 访问 x 中的值与直接使用 x 是等效的。

// 总之，在 C++ 中，引用已经隐式地进行了解引用操作，不需要显式地写出 * 运算符来
// 访问所引用的对象。

#include <iostream>
using namespace std;
int z = 15;
int &f() { return z; }
int main()
{
    f() = 20;
    cout << z;
    return 0;
}
// f（）返回的是z的引用，第一句将引用修改为20，那么z的值也变成了20

#include <iostream>
using namespace std;

template <class T, class B>
T maxinum(T value1, B value2)
{
    if (value1 > value2)
    {
        return value1;
    }
    else
        return value2;
}

int main()
{
    cout << maxinum(2, 5.6) << endl;
    cout << maxinum<double>(2.3, 5.2) << endl;
}

// 在这个程序中，虽然maximum是一个模板函数，但在调用时没有显式地指定其模板参数。这
// 是因为C++具有类型推导功能，可以根据传递给函数的实参自动确定模板参数的类型。

// 例如，在main函数中，第一次调用maxinum函数时传递了整数2和5作为实参。由于这些实
// 参都是整数类型，编译器会自动将T推导为int类型，因此无需在调用maxinum函数时显式
// 指定模板参数类型。

// 如果想要显式指定模板参数类型，可以使用<int>或<double>等格式在函数名后面添加
// 尖括号来指定。例如：

// cout << maxinum<int>(2, 5) << endl;
// cout << maxinum<double>(2.3, 5.2) << endl;
// 上述代码将分别显式指定模板参数类型为int和double，而不依赖于编译器的类型推导功能。

#include <iostream>
#include <fstream>
using namespace std;
#define MAX 10
class Student
{
public:
    char name[25];
    int Ex1, Ex2;
};
int main()
{
    Student st[MAX];
    int count = 0;
    ifstream in("afile.dat", ios::in);
    // ios::in 是 C++ 标准库中 ios 类的一个标志，用于指定文件打开模式。它表示以输
    // 入模式打开文件，即可读取文件中的数据。
    // 使用这个标志作为参数调用 ifstream 构造函数时，将创建一个输入文件流对象并以输
    // 入模式打开指定的文件。例如：
    // c++
    // ifstream in("test.dat", ios::in);
    // 这个代码片段中，第二个参数 ios::in 明确告诉了 ifstream 对象要以输入模式
    // 打开 "test.dat" 文件，以便从该文件中读取数据。
    // 还有其他的文件打开模式，其中一些常用的模式包括：
    // ios::out：以输出模式打开文件，即可向文件写入数据。
    // ios::binary：以二进制模式打开文件，允许读取或写入二进制数据而不进行任何格式
    // 转换。这个标志通常与 ios::in 或 ios::out 结合使用。
    // ios::app：在文件末尾追加数据而不覆盖原有内容，需要结合 ios::out 标志使用。
    // ios::trunc：如果文件已存在，则先清空文件内容，再打开文件进行写操作；如果文件
    // 不存在，则创建该文件并以写模式打开。
    // 它们可以分别单独使用或者以按位或（|）的方式组合使用，如：
    // c++
    // ofstream out("output.txt", ios::out | ios::app);
    // 这行代码将创建一个输出文件流对象 out 并以输出模式打开名为 "output.txt" 的文
    // 件，在文件末尾追加写入数据。

    // ios 和 std 是 C++ 标准库中的两个不同的命名空间。

    // std 命名空间包含了所有标准库的组件，包括输入、输出、容器、算法等。std 命名空间
    // 在头文件中定义，我们需要使用 using namespace std; 或者使用 std:: 前缀来访问
    // 其中的成员。

    // 而 ios 命名空间则包含了用于流的输入和输出操作的基础设施。它定义了一些与 I/O 流有
    // 关的类和函数，比如 ios_base、basic_ios、basic_istream、basic_ostream 和
    // basic_streambuf 等，同时也定义了一些与流相关的枚举值，如文件打开模式、流格式
    // 控制等。

    // 因此，在使用流时，我们需要同时引入这两个命名空间：

    // c++
    // #include <iostream>
    // #include <fstream>

    // using namespace std;

    // int main() {
    //     ifstream in("test.dat", ios::in);
    //     // ...
    //     return 0;
    // }
    // 在这个例子中，我们使用了 ifstream 类型和 ios::in 常量，它们都位于 std 和
    //  ios 命名空间中，因此需要通过 using namespace std; 来引入这两个命名空间。

    // .dat 文件是一种通用的数据文件格式，它可以包含任意类型和结构的数据。.dat 文件
    // 可以由各种编程语言创建和读取，其中包括 C 和 C++ 等语言。
    // .dat 文件本身并不是一种标准的文件格式，因此其具体的内容和结构完全取决于创建和使
    // 用该文件的程序。在某些情况下，.dat 文件可能只是一个简单的二进制文件，也可能包
    // 含特定的结构化数据。在读取 .dat 文件时，需要了解该文件的确切格式和结构，并使用
    // 正确的方法来解析文件中的数据。
    // 通常，.dat 文件命名方式比较灵活，可以根据使用场景进行任意取名，例如
    // data.dat、input.dat、output.dat 或者 foobar.dat 等等。
    if (!in)
    {
        cout << "Cannot open test.dat.\n";
        return 1;
    }
    // if (!in) 相当于 if (in.fail())，它使用 fail() 成员函数来判断上一次 I/O
    // 操作是否失败。如果失败，则表示文件打开失败，此时需要输出错误信息并返回 1
    // 表示程序异常结束。如果该条件不成立，则说明文件已经成功打开，可以继续后续的
    // 操作了。
    // 在 C++ 中，对于流对象 stream 来说，可以使用以下成员函数来查询其状态：

    // good()：当流对象未出错时，该函数返回 true。
    // eof()：当流到达文件末尾时，该函数返回 true。
    // fail()：当最近一次 I/O 操作失败时，该函数返回 true。
    // bad()：当流对象发生致命错误时，该函数返回 true。
    // 对于输入流对象 in，由于它是通过 ifstream 构造函数创建的，因此默认情况下它的
    // 状态为“好的”。但是，如果在打开文件时出现错误，则 failbit 标志会被置位，表示
    // 上一次 I/O 操作失败。因此，!in 表达式将在这种情况下返回 true，表示文件打开失败。

    // 在 C++ 中，程序的返回值是表示程序运行状态的重要标识之一。程序的返回值可以是任
    // 何整数值，其中常用的有 0 和非零整数。

    // 通常情况下，程序正常结束时应该返回 0，表示程序运行成功完成。在这个例子中，当文
    // 件打开失败时，我们使用 return 1; 表示程序以异常状态结束，并返回一个非零整数，
    // 表示程序未能成功完成其任务。

    // 这种做法的好处是可以让程序的调用者了解程序的运行状态。如果程序返回值为 0，则说明
    // 程序已经成功完成操作；如果返回其他非零整数，则说明程序在处理过程中遇到了问题或者
    // 出现错误，需要进行进一步的处理或者调试。

    // 另外，返回值为 1 在某些操作系统中被约定为表示程序发生了一般性错误，因此在这种情
    // 况下返回 1 也是一种比较常见的做法。
    in >> st[count].name >> st[count].Ex1 >> st[count].Ex2;

    while (!in.eof())
    {
        cout << st[count].name << " " << st[count].Ex1 << " " << st[count].Ex2 << "\n";
        count++;

        if (count >= 10)
        {
            cout << "Exceed MAX: " << MAX << endl;
            in.close();
            return (-1);
        }
        // 返回值为负数是一种常见的做法，它通常用来表示程序出现了某种错误或者异
        // 常情况，例如无法打开文件、输入数据格式错误等等。由于返回值为非零整数
        // ，因此可以让程序调用者了解程序执行过程中是否出现了异常情况。
        in >> st[count].name >> st[count].Ex1 >> st[count].Ex2;
    }
    in.close();
    return 0;
}

#include <iostream>
using namespace std;
class Oyster
{
public:
    Oyster(string genusString)
    {
        genus = genusString;
    }
    string getPhylum() const
    {
        return "Mollusca";
    }
    virtual string getName() const
    {
        return "Oyster class";
    }
    string getGenus() const
    {
        return genus;
    }
    virtual void print() const = 0;

private:
    string genus;
};
class VirginiaOyster : public Oyster
{
public:
    VirginiaOyster() : Oyster("Crassostrea") {}
    virtual string getName() const
    {
        return "VirginiaOyster class";
    }
    virtual void print() const
    {
        cout << "Phylum: " << getPhylum().c_str() << "\tGenus: " << getGenus().c_str() << "\tName: " << getName().c_str();
    }
    // 在C++中，c_str()是一个成员函数，用于将std::string类型的字符串转换为const
    // char*类型的字符串，也就是C风格的字符串。

    // 由于std::string类型的字符串和C风格的字符串在底层实现上不同，因此当需要将
    // std::string类型的字符串传递给C语言的API或函数时，就需要使用c_str()函数进行转
    // 换。
    // C++标准库中的std::string类型是一个封装了动态分配内存的字符串类
    // 该函数返回一个指向内部字符数组的指针，可以被用于读取字符串的内容，但不能修改它。
    // 另外，由于该指针指向的是std::string内部的元素，因此如果原始的std::string发生了
    // 改变，那么该指针可能会失效。

    // 在此处的转换可以不写这个函数，效果一致
};
// 这个程序运行的结果说明了C++中多态性的概念，即基类指针可以指向派生类的对象，并
// 且通过virtual关键字可以实现动态绑定，保证了在派生类中覆盖了基类的虚函数之后，
// 通过基类指针调用该函数时能够正确地执行派生类的版本。
// 如果还要调用基类中的虚函数，需要加上作用域限定符

int main()
{
    VirginiaOyster oyster;
    Oyster *baseClassPtr;
    baseClassPtr = &oyster;
    baseClassPtr->print();
    cout << endl;
    return 0;
}

// 虚函数的覆盖是一种多态性的体现，它允许派生类重写基类的虚函数，并且在运行时根
// 据对象的实际类型来决定调用哪个版本的函数。

// 但如果派生类不需要对基类中的某个虚函数做出任何更改，或者该虚函数已经符合其需
// 求，则无需覆盖该函数。

// 如果一个派生类没有覆盖基类的虚函数，那么当使用该派生类的对象调用该虚函数时，
// 将会调用基类中的实现。

// 需要注意的是，如果基类中的虚函数被声明为纯虚函数，那么所有的派生类都必须提供其
// 自己的实现，否则派生类就会变成抽象类，不能被直接实例化。

#include <iostream>
using namespace std;
class Dividezero
{
public:
    Dividezero() : out("EXCEPTION :Division by zero attempted.") {}
    string display() const
    {
        return out;
    }

private:
    string out;
};
double arithmetic(int n, int d)
{
    if (d == 0)
        throw Dividezero();

    // Dividezero() 表示在 throw 关键字处创建的一个临时对象。这个临时对象是通过
    // 调用 Dividezero 类的默认构造函数来创建的。

    // 在 C++ 中，可以通过在类型名后面加上一对圆括号来显式地调用该类型的默认构造函
    // 数，从而创建一个临时对象。这个临时对象通常用于函数返回值、函数参数或者类成员
    // 函数的返回值等场合。

    // 在上面的代码中，throw Dividezero() 创建了一个临时的 Dividezero 对象，并将
    // 其作为异常对象抛出。由于这个对象是临时创建的，它的生命周期只存在于当前语句中。
    // 一旦异常被抛出，该对象就会被销毁。
    return static_cast<double>(n) / d;
}

// 在C++中，有四种类型转换操作符：static_cast、dynamic_cast、reinterpret_cast
// 和 const_cast。

// static_cast：用于基本数据类型之间的转换（如 int 转 double），还可以将指针或引
// 用转换为其他指针或引用（如派生类指针转为基类指针）。

// dynamic_cast：用于将一个类的指针或引用转换为另一个相关的类的指针或引用。它会在
// 运行时检查类型是否兼容，如果不兼容就返回 null 指针。

// reinterpret_cast：一种较为危险的类型转换，它将任何指针类型转换为任何其他指针类
// 型，甚至是不同类型之间的指针。这个操作符主要是用于底层编程和与硬件交互等场景，
// 需要谨慎使用。

// const_cast：用于将 const 限定符添加或移除，例如去除 const 属性以便对变量进行
// 修改，或者添加 const 属性以禁止对变量的修改。

// 除了这些类型转换操作符，还有其他类型转换机制，例如使用 std::any_cast 或
// std::variant 实现任意类型转换。需要根据具体情况选择合适的类型转换方式，避
// 免出现未定义行为或逻辑错误。
int main()
{
    try
    {
        cout << arithmetic(24, 6) << endl;
        cout << arithmetic(1, 3) << endl;
        cout << arithmetic(9, 0) << endl;
    }
    catch (Dividezero &e)
    {
        cout << e.display() << endl;
    }
    return 0;
}

// 分别举例说明这四种类型转换操作符的使用场景：

// static_cast：将 int 类型转换为 double 类型
// c++
// int a = 5;
// double b = static_cast<double>(a); // 将 int 类型的 a 转换成 double 类型的 b
// 还可以将指针或引用转换为其他指针或引用，如下例所示：

// c++
// class Base {
// public:
//     virtual void func() {}
// };

// class Derived : public Base {
// public:
//     void func() override {}
// };

// int main() {
//     Derived d;
//     Base* pb = static_cast<Base*>(&d); // 派生类指针转基类指针
//     pb->func(); //调用基类的虚函数
//     return 0;
// }
#include <iostream>
using namespace std;
class Base
{
public:
    virtual void func()
    {
        cout << "father";
    }
};

class Derived : public Base
{
public:
    void func() override
    {
        cout << "son";
    }
};

int main()
{
    Derived d;
    Base *pb = static_cast<Base *>(&d); // 派生类指针转基类指针
    pb->func();                         // 调用基类的虚函数
    return 0;
}
// d中的虚函数表里面储存的是子类的覆盖的函数，即使进行类型转换，也只是把子类多于的函数成员扔掉，但是覆盖的子类虚函数不会改变

// dynamic_cast：将一个类的指针或引用转换为另一个相关的类的指针或引用
// c++
// class Animal {
// public:
//     virtual ~Animal() {}
// };

// class Dog : public Animal {
// public:
//     void bark() { std::cout << "Woof!" << std::endl; }
// };

// int main() {
//     Animal* animal = new Dog();
//     //注意基类指针指向子类的时候只是能够操控的范围包含父类，没有子类，但是子类独有的内容仍然存在，并没有消失。
//     Dog* dog = dynamic_cast<Dog*>(animal); // 将 Animal 类型的指针转换为 Dog 类型的指针
//     if (dog) {
//         dog->bark(); // 如果转换成功，则调用 Dog 的成员函数
//     } else {
//         std::cout << "Conversion failed" << std::endl; // 如果转换失败，则返回空指针
//     }
//     delete animal;
//     return 0;
// }

// 注意dynamic_cast的写法，一定要判断是否转换成功

// reinterpret_cast：将任何指针类型转换为任何其他指针类型
// c++
// int a = 42;
// char* c = reinterpret_cast<char*>(&a); // 将 int 类型的指针转换为 char* 类型的指针
// std::cout << *c << std::endl; // 输出的是 a 的低位字节，因为内存布局与机器的字节序有关，可能输出不同的结果
// 需要注意的是，reinterpret_cast 的使用需要十分小心，因为它可以将不同类型
// 之间的指针进行强制转换，可能会导致未定义行为或安全问题。

// const_cast：用于将 const 限定符添加或移除
// c++
// const int a = 42;
// int& b = const_cast<int&>(a); // 去除 const 属性
// b = 100;
// std::cout << a << std::endl; // 输出 100
// 需要注意的是，去除 const 属性并修改变量的值是一种非常危险的行为，容易出现
// 意外错误。

#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
#include <iostream>
int main()
{
    char *str = (char *)malloc(100);
    strcpy(str, "hello");
    free(str);
    // 释放之后，指向位置不变
    if (str != NULL)
    {

        strcpy(str, "world");
        // 输出为空
        printf(str);
    }
    // 在C语言中，free函数是用来释放动态分配的内存。当我们在程序中使用malloc或calloc
    // 等函数分配了一块内存后，就可以通过指针访问这块内存。但是在使用完这块内存后，我们
    // 需要使用free函数将其归还给操作系统。

    // 当我们调用free函数时，我们传递给它指向要释放内存的指针。free函数会将这个指针所指
    // 向的内存空间标记为可用，以便其他部分的程序可以再次使用它。但是，free函数并不会修
    // 改指针本身的值，也就是说，指针仍然指向之前分配的内存空间。因此，如果在free函数之
    // 后继续使用该指针，可能会导致未定义的行为（例如访问已经被释放的内存）。

    // 因此，在调用free函数后，建议将指针设置为NULL，以避免悬空指针的问题
}
// 如果strcpy函数的源字符串空间不足，会导致缓冲区溢出（buffer overflow）的问题。
// 具体来说，strcpy函数会试图将整个源字符串复制到目标字符串中，如果源字符串长度超
// 过了目标字符串的大小，就会覆盖目标字符串之后的内存空间，导致未定义的行为。

// 这种情况下，可能会对程序的内存或数据造成损坏，导致程序崩溃或者产生意想不到的结
// 果。因此，在使用strcpy函数时，需要确保目标字符串有足够的空间来存储源字符串的内
// 容，并且在进行复制操作之前，最好检查源字符串的长度，以避免发生缓冲区溢出的问题。

// 另外，为了更加安全地进行字符串复制操作，也可以使用更加安全的库函数，例如strncpy
// 和memcpy等。这些函数都提供了更好的参数控制，可以避免缓冲区溢出等问题，并且在执行
// 过程中也能够返回错误信息，帮助我们更好地处理异常情况。

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
class Person
{
public:
    Person(char *pName);
    ~Person();
    // 修改
    Person &operator=(const Person &rhs)
    {

        delete[] pFirstName;
        pFirstName = new char[strlen(rhs.pFirstName) + 1];
        strcpy(pFirstName, rhs.pFirstName);
        return *this;
    }
    // 在类的内部创建自身类的对象可以使用该对象访问私有成员变量。因为在同一个类的不
    // 同对象之间，它们的私有成员变量是可以相互访问的。

    // 例如，考虑以下代码：

    // cpp
    // class MyClass {
    // private:
    //     int x;
    // public:
    //     MyClass(int n) : x(n) {}
    //     void printX() {
    //         MyClass obj(100);
    //         std::cout << "x is " << obj.x << std::endl;
    //     }
    // };
    // 在上面的代码中，printX() 函数会在其内部创建一个 MyClass 类型的对象 obj，然
    // 后使用 obj 对象访问该类的私有成员变量 x。这是合法的，因为 obj 和调用 printX()
    // 函数的对象都属于同一个类，它们之间的私有成员变量是可以相互访问的。

    // 需要注意的是，尽管在类的内部可以直接访问其私有成员变量，但为了保护数据安全性和封
    // 装性，通常情况下应该通过成员函数来访问和修改私有成员变量，并且尽量避免在类的外
    // 部直接访问私有成员变量。
private:
    char *pFirstName;
};
Person::Person(char *pName)
{
    pFirstName = new char[strlen(pName) + 1];
    strcpy(pFirstName, pName);
}
Person::~Person()
{
    delete[] pFirstName;
}
int main()
{
    Person Mike("Mike");
    Person John("John");
    Mike = John;
    return 0;
}
// 这个程序创建了两个名为Mike和John的Person对象，每个对象都有一个由字符串构成的
// 名字。在这里，类的构造函数负责使用new运算符动态分配内存空间，并将pFirstName指
// 针指向字符串。

// 然后，程序执行了赋值操作Mike = John。因为C++默认生成浅拷贝的赋值运算符，所以
// 只是将Mike对象的pFirstName指针指向了John对象的pFirstName指针所指向的字符串。
// 这导致了两个问题：

// 内存泄漏：Mike指向的原始字符串内存空间没有被释放，而且也无法访问了。
// 不正确的数据共享：现在，Mike和John共享同一块内存空间，任何对于该内存空间的修改
// 都会影响到它们两个。
// 之后，程序退出，但没有释放内存空间，造成了内存泄漏问题。

// 因此，要解决这些问题，需要手动实现拷贝构造函数和拷贝赋值运算符函数来确保正确的
// 深拷贝。同时，在程序结束时应该释放动态分配的内存空间。

#include <iostream>
using namespace std;
template <class type>
int arrMin(type arr[], int n)
{
    type minn = arr[0];
    for (int i = 1; i < n; i++)
    {
        minn = min(minn, arr[i]);
    }
    return minn;
}
int main()
{
    int arr1[] = {10, 20, 15, 12};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    char arr2[] = {1, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << arrMin<int>(arr1, n1) << endl;
    cout << arrMin<char>(arr2, n2) << endl;
    return 0;
}

int main()
{
    string line;
    ifstream my_file("1.txt", ios::in);
    if (my_file.is_open())
    {
        while (!my_file.eof())
        {
            getline(my_file, line);
            cout << line << endl;
        }
        my_file.close();
    }
    else
        cout << "Unable to open file";
    return 0;
}
// 依旧是典型的利用文件操作函数读取数据的例子

#include <iostream>
using namespace std;
class computer
{
protected:
    string name;

public:
    virtual void print() = 0;
};
class Macintosh : public computer
{
    string color;

public:
    void print()
    {
        cout << "name:" << name << endl;
        cout << "color: " << color << endl;
    }
    Macintosh(string name, string color)
    {
        this->name = name;
        this->color = color;
    }
};
int main()
{
    computer *p;
    Macintosh imac("joe's IMAC", "Blue");
    p = &imac;
    p->print();
    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;
class String
{
public:
    String(const char *str = NULL)
    {
        if (str == NULL)
        {
            m_data = NULL;
        }
        else
        {
            m_data = new char[strlen(str) + 1];
            strcpy(m_data, str);
        }
    }
    String(const String &other)
    {
        if (other.m_data == NULL)
        {
            m_data = NULL;
        }
        else
        {
            m_data = new char[strlen(other.m_data) + 1];
            strcpy(m_data, other.m_data);
        }
    }
    ~String()
    {
        if (m_data != NULL)
            delete[] m_data;
    }
    String &operator=(const String &other)
    {
        if (this == &other)
            return *this;
        // 在 C++ 中，自赋值指的是将一个对象赋值给它本身。例如，假设有一个名为 a 的对象，执行 a = a 就是自赋值。
        // 当发生自赋值时，会出现以下问题：
        // 内存泄漏：如果在执行自赋值操作之前分配了内存，则会导致内存泄漏，因为在赋值之后无法访问该内存。
        // 逻辑错误: 自赋值可能会导致对象状态不一致或出现未定义行为。例如，如果在自赋值之前调用了一个释放资源的函数，那么就会出现问题。
        // 性能下降：自赋值会导致额外的开销，因为它需要复制自己的数据。这样做没有任何意义，因为结果与原始数据相同。
        // 为避免这些问题，应该在进行赋值操作之前检查自赋值，并在必要时避免自赋值。

        // 自赋值可能会导致数据出错，下面是一个例子：

        // cpp
        // class Test {
        // public:
        //     Test(int value) : value_(value) {}
        //     void setValue(int value) {
        //         if (value_ != value) {
        //             value_ = value;
        //         }
        //     }
        // private:
        //     int value_;
        // };

        // Test obj(1);
        // Test &ref = obj;
        // ref = ref; // 自赋值，obj 的值变为随机值

        // 在这个示例中，我们定义了一个 Test 类，其中包含一个整数成员变量 value_ 和一个 setValue() 成员函数，用于设置 value_ 的值。与之前的示
        // 例不同，setValue() 函数现在检查新值是否等于旧值，如果相等就不更新。

        // 接着，我们创建了一个名为 obj 的 Test 对象，并将其地址赋给一个名为 ref 的引用变量。在第三行代码中，我们将变量 ref 自赋值，即将其当
        // 前的值（即 obj 对象的地址）赋给它本身。由于 setValue() 函数检查新值是否等于旧值，并且自赋值操作不改变 ref 的值，所以 value_ 的值
        // 不会被更新，但是 obj 对象的值会变成随机值，因此这种自赋值会导致数据出错。

        // 自赋值可能会导致数据出错的原因是，它破坏了对象的不变量（即对象在任何时候都应该保持一致的状态和属性）。在这个特定的示例中，当我们将 ref 自
        // 赋值时，它实际上没有改变其所引用的对象的值。但是，在 C++ 中，引用是以指针的形式实现的，因此自赋值将使 ref 的内部指针指向 ref 本身的地址，
        // 而不是原来的对象地址。

        // 这意味着，如果我们尝试使用 ref 来访问原来的对象（即 obj 中的 value_ 成员），由于 ref 指向自己而不是 obj，这将导致未定义行为。最常见的情
        // 况是访问一个不存在或未初始化的内存位置，其结果是无法预测的，通常表现为随机值。

        // 因此，在 C++ 中，自赋值必须谨慎处理，并且需要确保它不会破坏对象的不变量。
        delete[] m_data;
        m_data = new char[strlen(other.m_data) + 1];
        strcpy(m_data, other.m_data);
        return *this;
    }

private:
    char *m_data;
};

#ifndef COW_H
#define COW_H

#endif

// 这段代码是一个经典的C++头文件保护（header guard），它的作用是确保在编译时
// 每个头文件只被包含一次，以防止由于重复包含而导致的编译错误。当编译器遇
// 到 #ifndef 指令时，它会检查该标识符是否已经被定义过了。如果没有，则继续
// 编译下面的代码，并用 #define 定义这个标识符。如果已经被定义过了，那么编译
// 器会跳过这段代码直接去找后面的代码。

// 这种方法可以避免头文件被多次包含所带来的问题，并提高编译效率。

// 通常情况下，在头文件名前后添加下划线并不会改变头文件的含义。因此，
// "_STRING_H_" 和 "STRING_H" 在功能上没有区别。

// 然而，值得注意的是，命名约定可能因编程语言、编译器或项目而异。有些开发人员可
// 能会选择添加下划线来区分系统定义的头文件和用户定义的头文件，而其他人可能使用完全不同的命名约定。

#include <windows.h>
#include <iostream>
#include <ctime>
using namespace std;

class test
{
private:
    int x, y;
    clock_t t; // 时钟，用来记录系统时间，从0开始

public:
    test()
    {
        x = 5;
        y = 5;
        t = clock();
    }
    void gotoxy(int x, int y)
    {
        HANDLE h;
        // 句柄,对象的索引
        // 在计算机科学中，句柄（Handle）是一个引用对象的标识符。它通常是一个指向对象（如内存块或文件）存储地址的指针或索引，这个指针或索引不直接暴露给应用
        // 程序，而是被封装在对象的抽象句柄中。使用句柄可以让应用程序间接地引用和访问操作系统或其他进程中的对象，同时还能保护对象的内部数据结构和实现细节。
        // 在 Windows 操作系统中，句柄是一种通用的技术，用于表示各种资源，例如窗口、设备上下文、文件、线程等。每个句柄都有自己的类型和指定的生命周期，当句
        // 柄不再需要时，必须显式地释放，以防止资源泄漏或占用过多的内存资源。
        // 总之，句柄是一种重要的编程概念，其主要作用是提供对底层资源的访问和管理机制，为应用程序和操作系统之间提供了一个受控的、封装的交互界面。

        COORD c; // 结构体,坐标值

        // COORD是Windows API中的一个结构体，用于表示二维平面上的坐标。它通常用于控制台应用程序中，指定光标的位置或者控制输出文本的位置。

        // COORD结构体定义如下：

        // typedef struct _COORD {
        //   SHORT X;
        //   SHORT Y;
        // } COORD, *PCOORD;
        // 其中，X和Y分别表示坐标的横向和纵向位置，都是16位有符号整数类型（SHORT）。COORD结构体可以用作各种Windows API函数的参数，包括绘图函数、窗口函数等等。

        // 在控制台应用程序中，可以使用Windows API函数SetConsoleCursorPosition来设置光标的位置，例如：

        // COORD cursorPos = { 10, 5 };
        // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
        // 这个例子将光标移动到控制台窗口中第5行第10列的位置。
        c.X = x;
        c.Y = y;
        h = GetStdHandle(STD_OUTPUT_HANDLE);
        // GetStdHandle是Windows API中的一个函数，用于获取标准输入、输出和错误的句柄。它的原型定义如下：

        // HANDLE WINAPI GetStdHandle(
        //   _In_ DWORD nStdHandle
        // );
        // 其中，nStdHandle参数指定要获取的标准句柄类型，它可以取以下值：

        // STD_INPUT_HANDLE：标准输入句柄。
        // STD_OUTPUT_HANDLE：标准输出句柄。
        // STD_ERROR_HANDLE：标准错误句柄。
        // GetStdHandle返回一个句柄（HANDLE）值，用于标识指定的标准句柄。在控制台应用程序中，通常使用GetStdHandle和WriteConsole函数来向控制台输出文本信息。

        // STD_OUTPUT_HANDLE是Windows API（应用程序编程接口）中的一个常量，它指定了标准输出设备的句柄。在Windows中，标准输出设备通常是
        // 控制台窗口或者重定向到文件的命令行窗口。

        // 在C++、C#等编程语言中，可以使用GetStdHandle函数来获取STD_OUTPUT_HANDLE句柄，然后利用WriteFile函数将数据输出到标准输出设备上。这
        // 些API函数可以帮助开发人员实现各种与控制台交互的操作，如输出文本、修改控制台窗口大小和颜色等。
        // 例如，GetStdHandle(STD_OUTPUT_HANDLE)获取标准输出句柄，可以将其传递给WriteConsole函数，将文本输出到控制台屏幕上：

        // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        // WriteConsole(hConsole, "Hello, world!", 13, NULL, NULL);
        // 这个例子将字符串"Hello, world!"输出到控制台屏幕上。
        SetConsoleCursorPosition(h, c);
        // SetConsoleCursorPosition是Windows API中的一个函数，用于设置控制台窗口光标的位置。它的原型定义如下：

        // BOOL WINAPI SetConsoleCursorPosition(
        //   _In_ HANDLE hConsoleOutput,
        //   _In_ COORD  dwCursorPosition
        // );
        // 其中，hConsoleOutput是控制台输出句柄，dwCursorPosition是一个COORD结构体，表示要设置的光标位置。

        // 例如，可以使用以下代码将控制台窗口光标移动到第5行第10列的位置：

        // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        // COORD cursorPos = { 10, 5 };
        // SetConsoleCursorPosition(hConsole, cursorPos);
        // 这个例子首先调用GetStdHandle获取标准输出句柄，然后创建一个COORD结构体，表示光标要移到第5行第10列的位置，最后调用SetConsoleCursorPosition函数设置光标位置。

        // 注意，控制台窗口的左上角坐标为(0,0)，并且行号和列号都从0开始计数。因此，以上示例将把光标移动到第6行第11列的位置。
    }
    void draw()
    {
        gotoxy(x, y);
        cout << "●";
    }
    void erase()
    {
        gotoxy(x, y);
        cout << " ";
    }
    // 这个函数
    void key(clock_t &t, int tt)
    {
        if (clock() - t > tt)
        {

            erase();
            if (GetAsyncKeyState(VK_ESCAPE))
                exit(0);
            // GetAsyncKeyState 是一个 Windows API 函数，用于检测指定虚拟按键的状态，返回值表示该按键是否被按下或处于被按下的状态。
            // 该函数接受一个 int 类型的参数 vKey，表示要检测的虚拟按键的键值。同时，GetAsyncKeyState 还可以接受一个可选的 SHORT 类型的参数 lpwTransKey，
            // 代表虚拟键的转换状态。
            // 当函数返回值的最高位（即第 16 位）为 1 时，表示该虚拟键在此次调用时处于按下或持续按下状态；当最高位为 0 时，表示该虚拟键未被按下。其余位则表示
            // 该虚拟键的状态信息。
            // 需要注意的是，GetAsyncKeyState 可以检测到所有当前正在按下的键，而不仅仅是由当前程序所关心的键。因此，如果需要通过该函数来实现游戏控制等操作，需
            // 要对输入进行过滤和处理，以确保只响应与游戏逻辑相关的按键事件。
            if (GetAsyncKeyState(VK_LEFT))
            {
                --x;
                if (x < 0)
                    x = 78;
            }
            if (GetAsyncKeyState(VK_RIGHT))
            {
                ++x;
                if (x > 78)
                    x = 0;
            }
            if (GetAsyncKeyState(VK_UP))
            {
                --y;
                if (y < 0)
                    y = 24;
            }
            if (GetAsyncKeyState(VK_DOWN))
            {
                ++y;
                if (y > 24)
                    y = 0;
            }
            draw();
            t = clock();
        }
    }
    void move()
    {
        while (true)
        {
            key(t, 10);
        }
    }
};

int main()
{
    test t;
    t.move();
    return 0;
}

#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>
using namespace std;

vector<string> v;   // 储存数字
int len = 5;        // 用来限制只输出5个
const int pace = 4; // 表示迈步的大小

void movee(long &x, char c) // 用来表示键盘提供的窗口移动
{
    if (c == '-')
        x -= pace;
    else if (c == '+')
        x += pace;
}

void randd() // 用来产生随机数
{
    string x;
    int c = 0;
    while (c++ < 15)
    {
        x += to_string(rand() % 10);
    }
    v.push_back(x);
    len++;
}
void display() // 用来显示
{
    for (int i = len - 5; i < len; i++)
    {
        cout << v[i] << endl;
    }
}
int main()
{
    v.push_back("123123124124124");
    v.push_back("213421312311232");
    v.push_back("123214214214124");
    v.push_back("123523523453242");
    v.push_back("124123412341234"); // 先初始化一下
    display();
    RECT rect; // rect对象用来存储一个矩形框的左上角坐标、宽度和高度

    //     RECT是Windows API中的一个结构体，用于表示一个矩形框的左上角坐标、宽度和高度。它定义在Windef.h头文件中，具体定义如下：

    // typedef struct _RECT {
    //     LONG left;
    //     LONG top;
    //     LONG right;
    //     LONG bottom;
    // } RECT, *PRECT, NEAR *NPRECT, FAR *LPRECT;
    // 其中，left和top表示矩形框左上角的坐标，right和bottom表示矩形框右下角的坐标。这四个变量的类型都是LONG型，即32位有符号整数。

    // RECT结构体常用于Windows图形界面编程中，例如创建窗口、绘制图形、控制窗口的位置和大小等操作。GetWindowRect函数就是一个使用
    // RECT结构体的例子，它可以获取一个窗口的大小和位置信息，并将其存储在RECT结构体中。通过对RECT结构体中的不同成员进行修改，可以实现控制和调整窗口的位置和大小。
    HWND hwnd = GetForegroundWindow();
    //     HWND是Windows API中的一个数据类型，它代表了一个窗口的句柄（handle）。在Windows操作系统中，每个窗口都有一个唯一的句柄用于标识和访问
    //     该窗口。HWND实际上是一个指向窗口结构体的指针，可以使用它来操纵和控制窗口。

    // 在Windows编程中，通常需要获取一个窗口的句柄才能对其进行各种操作，例如创建、关闭、隐藏、显示、移动、改变大小、发送消息等。可以通过
    // FindWindow、FindWindowEx、GetForegroundWindow等函数来获取当前活动窗口或指定窗口的句柄。另外，CreateWindowEx函数返回的也是一个窗口句柄。

    // 需要注意的是，由于HWND是一个指针类型，因此应该始终检查其是否为NULL，以避免悬空指针的问题。同时，在使用Windows API进行窗口操作时，也需
    // 要特别注意线程安全性和错误处理。
    GetWindowRect(hwnd, &rect); // 获得窗口相关数据

    //     这行代码使用了Windows API中的GetWindowRect函数，用于获取指定窗口的边框矩形的坐标。它的参数是一个窗口句柄（HWND类型）和一个
    //     RECT结构体的指针，表示将要存储窗口坐标信息的变量。

    // 具体用法为：

    // c++
    // BOOL GetWindowRect(
    //   HWND   hWnd,     // 窗口的句柄
    //   LPRECT lpRect    // 存储窗口坐标信息的RECT结构体指针
    // );
    // 调用该函数后，会将窗口的边框矩形左上角的坐标（left, top）和右下角的坐标（right, bottom）存储到RECT结构体中，以便后续操作。

    // 在这个代码中，hwnd是指向当前控制台窗口的句柄，而rect是保存窗口坐标信息的RECT结构体。调用GetWindowRect(hwnd, &rect)之后，rect就
    // 会被填充上该窗口的坐标信息，包括左上角坐标、宽度和高度等。

    char ch;
    long leftt = rect.left;
    long rightt = rect.right - rect.left;
    long topp = rect.top;
    long bottomm = rect.bottom - rect.top; // 保存基本数据
    while (1)
    {
        if (_kbhit()) // 如果有按键
        //         _kbhit()是一个C/C++标准库函数，它用于检测是否有键盘输入。该函数返回非零值表示当前有键盘输入等待被读取，否则返回0。

        // 具体用法为：

        // c++
        // int _kbhit(void);
        // 在这个代码中，程序会不断地调用_kbhit()函数来检查键盘是否有按键事件。如果有按键事件，则执行相应的操作。

        // 需要注意的是，_kbhit()函数只能检测缓冲区中的按键事件，无法检测实时输入的字符或控制键，因此可能会出现漏检或延迟检测的情况。如果需要实时响应键盘
        // 输入，建议使用Windows API中的GetAsyncKeyState或GetKeyState函数来实现。
        {
            ch = getch();
            if (ch == 72) // shang
            {
                movee(topp, '-');
                MoveWindow(hwnd, leftt, topp, rightt, bottomm, TRUE);
                // 这行代码使用了Windows API中的MoveWindow函数，用于移动和调整指定窗口的位置和大小。它的参数包括一个窗口句柄、窗口的新坐
                // 标（左上角坐标leftt和topp）、新的宽度rightt和高度bottomm，以及一个BOOL类型的值表示是否需要重绘窗口。

                // 具体用法为：

                // c++
                // BOOL MoveWindow(
                //   HWND hWnd,      // 窗口的句柄
                //   int  X,         // 新的左上角的x坐标
                //   int  Y,         // 新的左上角的y坐标
                //   int  nWidth,    // 新的宽度
                //   int  nHeight,   // 新的高度
                //   BOOL bRepaint   // 是否重绘窗口
                // );
                // 在这个代码中，hwnd是指向当前控制台窗口的句柄，leftt和topp是新的窗口左上角的坐标，rightt和bottomm是新的窗口宽度和高度。TRUE表
                // 示需要对窗口进行重绘，即刷新窗口的内容。

                // 调用MoveWindow函数后，会将指定的窗口移动到相应的坐标位置，并改变其大小。如果bRepaint参数为TRUE，则系统会自动重绘该窗口，否则就
                // 需要手动调用InvalidateRect函数或RedrawWindow函数来重绘窗口。
            }
            else if (ch == 80) // xia
            {
                movee(topp, '+');
                MoveWindow(hwnd, leftt, topp, rightt, bottomm, TRUE);
            }
            else if (ch == 75) // zuo
            {
                movee(leftt, '-');
                MoveWindow(hwnd, leftt, topp, rightt, bottomm, TRUE);
            }
            else if (ch == 77) // you
            {
                movee(leftt, '+');
                MoveWindow(hwnd, leftt, topp, rightt, bottomm, TRUE);
            }
            else if (ch == 32) // space
            {
                randd();
                system("cls");
                display();
            }
            else if (ch == 27) // esc
            {
                return 0;
            }
        }
    }
    return 0;
}

#include <iostream>
using namespace std;
class date
{
public:
    date() {}
    ~date()
    {
        cout << "---";
    }
};
date get()
{
    date c;
    return c;
}
// 先创建c对象，使用默认构造函数，然后返回他，这时候调用c的默认析构函数，将这个c对象创建一个临时变量，调用默认拷贝构造函数，这个临时对象再赋值给x，调用默认构造函数，
// 这个临时对象也进行析构，被销毁，然后将值传给x。整个过程进行了两次析构和两次拷贝构造函数，一次默认构造函数；
// 其中一个回合是因为局部变量导致的，另一个回合是临时变量导致的；都是先调用复制构造函数，然后再调用析构函数；
int main()
{
    date x = get();
    cout << "+++";
    return 0;
}

// 如果您的程序只输出一个"---"，那么可能是因为编译器进行了优化，将临时对象的创建和销毁合并了。这种优化】
// 称为NRVO（Named Return Value Optimization），它会尽可能地避免不必要的拷贝操作，提高程序效率。

// 在经过NRVO优化后，创建临时对象和变量x之间的拷贝操作被省略了，因此析构函数也不会被调用。这就是为什么您的程序只输出了一个"---"的原因。

// 需要注意的是，编译器是否进行优化取决于编译器本身和编译选项等因素。因此，如果您想保证程序的正确性，最好还是手动调用析构函数
// 来进行必要的清理工作，而不要依赖于编译器的优化。

// NRVO指的是命名返回值优化（Named Return Value Optimization），它是编译器针对函数返回值优化的一种技术。NRVO能够通过减少返回值构造和析构函数的调用次数来
// 提高程序的性能。

// NRVO的触发条件包括以下两个方面：
// 函数返回一个非临时对象，例如一个局部变量或者一个参数。
// 函数中只有一个return语句，并且这个return语句返回的是一个非临时对象。
// 当函数符合上述两个条件时，编译器会尝试使用NRVO来避免不必要的构造和析构函数的调用。

// C++中的赋值运算符可用于复制对象的值。对于基本数据类型和POD（Plain Old Data）类型，C++中的赋值运算符确实是按字节复制的。POD类型是指那些没有用户定义
// 的构造函数、析构函数和虚函数的类类型。

// 但是，对于包含动态分配内存、文件句柄等资源的类，C++中的赋值运算符需要进行深度复制，以确保每个对象都有自己独立的资源副本。这可以通过编写自定义赋值
// 运算符来实现。

// 此外，C++11引入了移动语义，允许在对象之间转移资源而不进行深度复制。这提高了效率并减少了内存消耗。

// POD 是一个 C++ 概念，代表 Plain Old Data （平凡的旧数据）。它通常用于描述一些可以被视为纯数据结构的 C++ 类型，这些类型没有构造函数、虚函数或非静态数据成员。下面是一些 POD 类型的例子：

// 基本数据类型，如 int、float 等。

// C 语言中的 struct 类型（C++11 之前），只包含 public 数据成员，并且每个成员都是 POD 类型。

// C++11 的 struct 类型，只包含 public 或者是全部是 constexpr 的数据成员，并且每个成员都是 POD 类型。

// 数组类型，如 char[]、int[] 等。

// 指针类型，如 int*、float* 等。

// 需要注意的是，POD 类型并不等同于标准布局类型（standard layout type），后者还要求类的继承关系和成员变量的顺序等满足特定条件。
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class File
{
private:
    fstream f;
    string s;
    int len;

public:
    File()
    {
        f.open("afile.txt", ios::binary | ios::in | ios::out);
    }
    ~File()
    {
        f.close();
    }
    void Reverse()
    {
        // string temp; //
        string temp(s.size(), ' ');
        // 这行代码定义了一个新的string对象temp，并使用s.size()指定了它的大小。' '是一个空格字符，表示将temp中的所有元素初始化为一个空格字符。

        // 具体来说，这行代码会在内存中分配一块足够大的连续空间来存储temp中的所有元素，并用空格字符对其进行初始化。因此，这行代码确保了temp有
        // 足够的空间来存储要拷贝的字符串。

        // 注意，这里使用的是resize()函数的另一种形式，可以同时指定字符串的长度和初始值。如果只需要改变字符串的长度而不需要初始化其元素，则可以
        // 使用resize()函数的另一种形式：

        // temp.resize(s.size()); // 将temp的长度设置为与s相同
        // 这行代码创建了一个大小为s.size()的temp字符串，但没有初始化其中的元素。
        for (int i = 0; i < s.size(); ++i)
        {
            temp[i] = s[s.size() - i - 1];
            // cout<<s[s.size()-i-1]<<endl;
        }

        s = temp;
    }
    void Read()
    {
        f.seekg(0, ios::end);
        // seekg() 函数是 C++ 中 istream 类的成员函数之一，用于设置输入流的读取位置。它的语法如下：

        // c++
        // istream& seekg (streampos position);
        // istream& seekg (streamoff offset, ios_base::seekdir dir);
        // 第一个形式将读写位置设置为 position 指示的位置，其中 position 是 streampos 值，表示从流开始处偏移多少个字符。
        // 例如，要将读写位置设置为第 100 个字符处，可以这样调用 seekg()：

        // c++
        // ifstream file("example.txt"); // 打开文件
        // file.seekg(100); // 将读写位置设置为第 100 个字符处
        // 第二个形式允许通过给出相对偏移量和查找方向来指定读写位置。offset 是一个整数值，表示相对于 dir 方向的偏移量。dir 可以是以下三个常量之一：

        // ios::beg：从流的开头开始计算偏移量（默认值）。
        // ios::cur：从当前读写位置开始计算偏移量。
        // ios::end：从流的末尾开始计算偏移量。
        // 例如，要将读写位置设置为文件末尾前 100 个字符处，可以这样调用 seekg()：

        // c++
        // ifstream file("example.txt"); // 打开文件
        // file.seekg(-100, ios::end); // 将读写位置设置为文件末尾前 100 个字符处
        // 需要注意的是，seekg() 函数只适用于带有定位能力的输入流，如文件流。对于无法定位的输入流，如标准输入流 cin，调用该函数可能会导致未定义行为。
        len = f.tellg();
        // tellg 是 C++ 标准库中的一个函数，用于获取输入流的当前位置或指针。

        // 它的基本语法如下：

        // streampos tellg();
        // 其中，streampos 是一个类型，表示输入流的位置或指针。它通常是一个整数类型。

        // 调用 tellg() 函数将返回当前读取位置相对于流开头的偏移量。这个偏移量可以被传递给 seekg 函数来重新设置输入流的位置。如果 tellg 函数
        // 返回值为 -1，则表示在调用该函数时出现了错误。
        s.resize(len);
        f.seekg(0, ios::beg);
        f.read((char *)s.c_str(), len);

        // read 是 C++ 标准库中的一个函数，用于从输入流中读取一定数量的字节。

        // 它的基本语法如下：

        // istream& read( char* buffer, streamsize count );
        // 其中，buffer 是一个指向字符数组的指针，表示将要被填充的缓冲区；count 是要读取的字节数。read 函数返回一个输入流对象的引用，可以用于链式操作。
        // 需要注意的是，在使用 read 函数之前必须先打开文件并指定 std::ios::binary 模式，以确保能够正确读取二进制数据。此外，在读取过程中也
        // 应该对读取的字节数进行检查，并根据实际情况处理可能出现的错误。
    }
    void Write()
    {
        f.seekp(0, ios::beg);

        f.write((char *)s.c_str(), s.size());
        // 这是一个 C++ 中的类成员函数 Write()，其中 f 是一个已经打开的文件对象，s 是要写入的字符串。

        // 此函数首先使用 seekp() 函数将文件指针移动到文件开头（ios::beg 表示文件开头），然后使用 write() 函数将 s 中的数据写
        // 入文件。write() 函数的第一个参数是要写入的数据的指针，这里使用 (char *)s.c_str() 将 std::string 类型的字符串转换为 char * 类型的指针；第二个参数是要写入的字节数，这里使用 s.size() 获取字符串的长度作为要写入的字节数。

        // 需要注意的是，在使用 write() 函数时，如果文件中已经存在一些数据，则新写入的数据会覆盖原有的数据。因此在调用 Write() 函数
        // 前需要确保文件中不存在重要的数据，或者对原有数据进行备份。
    }
};
int main()
{
    File f;
    f.Read();
    f.Reverse();
    f.Write();
    return 0;
}
// 静态联编（Static Binding）是指在程序编译时就确定了函数或变量的位置和大小，因此在程序运行时它们的地址是固定不变的。这种绑定方式可以提高
// 程序的执行效率，但也限制了程序的灵活性。

// 静态联编通常应用于传统的编译型语言，如C、C++等。在这些语言中，函数调用会直接转化为跳转指令，并且由于程序在编译时已经完全生成，所以在运行
// 时不需要进行额外的查找操作。因此，静态联编可以大大减少程序的运行开销。

// 然而，静态联编的缺点是它不能够支持动态加载和替换功能。如果某一个函数被多个模块引用，那么在修改该函数后，所有引用该函数的模块都必须重新进行
// 编译，才能使新的代码生效。这会带来很大的麻烦和不便。
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class test
{
private:
    string s;
    int pos;

public:
    void input()
    {
        cout << "input a string:";
        cin >> s;
    }
    int str2num(string s)
    {
        stringstream ss;
        int temp;
        ss << s;
        ss >> temp;
        return temp;
    }
    void output()
    {
        int i = 0;
        while (i < s.size())
        {
            // if (s[i] >= '0' && s[i] <= '9')
            if (s[i] < '0' || s[i] > '9')
            {
                s.erase(i, 1);
                // “erase()” 函数用于从 C++ 字符串中删除元素。第一个参数指定要删除的第一个字符的位置，第二个参数指定要删除的字符数。
            }
            else
                ++i;
        }
        cout << s << endl;
        cout << str2num(s) + 100 << endl;
    }
};
int main()
{
    test A;
    A.input();
    A.output();
    system("pause");
    return 0;
}

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
struct student
{
    int number;
    double score;
};

class test

{
private:
    int n;
    vector<student> a;
    vector<student>::iterator p;

public:
    test(int nn)
    {
        n = nn;
        student temp;
        for (int i = 0; i < n; ++i)
        {
            cout << "input number:";
            cin >> temp.number;
            cout << "input score:";
            cin >> temp.score;
            a.push_back(temp);
        }
    }
    void browse()
    {
        for (p = a.begin(); p != a.end(); ++p)
        {
            cout << "number:" << p->number << "-" << p->score << endl;
        }
    }
    static int sort1(student s1, student s2)
    {                               //------------------------------------------
        return s1.score > s2.score; // 这句 //------------------------------------------
    }
    void SORT()
    {
        sort(a.begin(), a.end(), sort1);
        // C++的sort函数是一个标准库中非常常用的排序函数，可以对数组、向量等容器进行排序。使用sort函数需要包含头文件#include<algorithm>。

        // sort函数有两种用法：

        // 对数组进行排序
        // c++
        // int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
        // int n = sizeof(arr)/sizeof(arr[0]);
        // std::sort(arr, arr+n);
        // 这里把数组名和元素个数作为参数传递给sort函数，它将会按照默认的升序方式对数组进行排序。

        // 对容器进行排序
        // c++
        // #include<vector>
        // std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6};
        // std::sort(vec.begin(), vec.end());
        // 这里使用了迭代器来指定需要排序的范围，即从vec的begin()到end()之间的元素进行排序。注意，这里必须先包含头文件#include<vector>。

        // sort函数还支持自定义排序方式，可以通过提供一个比较函数来实现。例如：

        // c++
        // bool compare(int a, int b) {
        //     return a > b; // 按照降序排列
        // }

        // int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
        // int n = sizeof(arr)/sizeof(arr[0]);
        // std::sort(arr, arr+n, compare);
        // 这样就会按照自定义的降序方式对数组进行排序。容器的排序方式类似，只需要在sort函数的第三个参数中传入自定义的比较函数即可。
    }
    void max_min()
    {
        SORT();
        p = a.begin();
        cout << "max:" << p->number << "-" << p->score << endl;
        p = a.end() - 1; // 这句
        cout << "min:" << p->number << "-" << p->score << endl;
    }
};
int main()
{
    test t(3);
    t.max_min();
    return 0;
}

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class test
{
private:
    string s;
    int n;
    ofstream f;

public:
    test()
    { //------------------------------------------
        f.open("test.txt", ios::app);
        // 这句 //------------------------------------------
        // ios::app是文件打开模式之一，表示以追加方式打开文件。如果文件不存在，则创建该文件；如果文件已存在，则将新数据附加到文件末尾。如果不
        // 指定打开模式，则默认情况下是以读写模式打开文件，这会清除文件中的所有内容并从头开始写入。
        if (!f)
            cout << "文件建立错误！" << endl;
    }
    ~test() { f.close(); }
    void turn()
    {
        cout << "input a number:";
        cin >> n;
        f << endl
          << n; // 这句
    }
};

int main()
{
    test t;
    t.turn();
    return 0;
}

#include <iostream>
using namespace std;
class test
{

private:
    int n;
    int a[10];

public:
    test(int nn) throw(int)
    // 在这个代码中，throw(int)是一个异常说明（exception specification），它告诉编译器这个函数可能会抛出int类型的异常。在C++11标准中，异
    // 常说明已经被弃用并不再建议使用，因为它们在某些情况下可能导致更多问题。因此，在现代C++编程中，我们通常不使用异常说明。
    {
        n = nn;
        if (n >= 10)
        {
            throw 100; // 这句
        }
        else
        {
            cout << "OK!" << endl;
        }
    }
};

int main()
{
    try
    {
        test(50);
    }                 //------------------------------------------
    catch (int error) // 这句 //------------------------------------------
    {
        if (error == 100)
        {
            cout << "subscript out of range!" << endl;
        }
    }
    return 0;
}
// 拷贝构造函数通常不能使用按值传递参数，因为这样会导致无限递归调用拷贝构造函数的问题，最终导致栈溢出。

// 具体来说，如果拷贝构造函数使用按值传递参数，则在函数调用时会创建一个新的对象作为参数的副本，然后将该副本作为参数传递给拷贝构造函
// 数。但是，由于拷贝构造函数的目的是创建给定对象的副本，因此它必须访问该对象的数据成员。如果拷贝构造函数使用按值传递参数，则在访
// 问参数对象的数据成员时，又会调用拷贝构造函数来创建对象的副本，从而导致无限递归。

// 因此，为了避免这种问题，拷贝构造函数通常使用按常量引用传递参数。这可以避免不必要的拷贝，并确保不会意外修改原始对象。


// 类模板从模板类中派生和模板类从类模板中派生有一些区别：

// 类模板从模板类中派生是指在定义一个新的类时，使用一个已有的类作为这个新类的基类。而模板类从类模板中派生则是指在定义一个新的类时，使
// 用一个已有的类模板作为这个新类的基类。

// 类模板从模板类中派生的语法如下:

// template <typename T>
// class BaseClass {
//     // ...
// };

// class DerivedClass : public BaseClass<int> {
//     // ...
// };
// 模板类从类模板中派生的语法如下:

// template <typename T>
// class BaseClassTemplate {
//     // ...
// };

// template <typename T>
// class DerivedClass : public BaseClassTemplate<T> {
//     // ...
// };
// 当从模板类派生时，派生类将基类中的所有成员都继承过来，包括数据成员和成员函数。而从类模板派生时，则只会继承模板参数与非模板成员，
// 而不会继承模板参数推导出来的具体类型的成员。

// 从模板类派生时，可以明确指定模板参数，也可以通过模板参数推导得到具体的模板参数；而从类模板派生时，必须明确指定模板参数。

// 总之，类模板从模板类中派生和模板类从类模板中派生的区别在于它们继承的成员不同，以及语法上略有不同。




#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
struct score
{
    int number;
    score *next;
};

class test
{
private:
    int n;
    score *head, *end, *p;

public:
    test() { n = 6; }

    void input()
    {
        head = new score;
        end = head; // 这段
        for (int i = 1; i <= n; ++i)
        {
            p = new score;
            cout << "input score:";
            cin >> p->number;
            end->next = p; // 在链表的最后加上一个p
            end = p;
        }
        end->next = 0; // 终止尾部
    }
    void output()
    {
        int i = 0;
        int max = 0, min = 11;
        int max_number = 0, min_number = 0;
        p = head;
        while (p->next != 0) // 终止判断
        {
            ++i;
            p = p->next;
            if (p->number > max)
            {
                max = p->number;
                max_number = i;
            }
            if (p->number < min)
            {
                min = p->number;
                min_number = i;
            }
        }
        p = head;
        i = 0;
        int sum = 0;
        while (p->next != 0)
        {
            p = p->next;
            ++i;
            if (i != max_number && i != min_number)
            {
                sum = sum + p->number;
            }
        }
        cout << "score=" << sum << endl;
    }
};

int main()
{
    test t;
    t.input();
    t.output();
    system("pause");
    return 0;
}

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
class test
{
private:
    fstream f;
    string::size_type n;
    map<string, string> a;
    map<string, string>::iterator p;

public:
    test() // 这个函数
    {
        string s, s1;
        f.open("1.txt", ios::in);
        while (true)

        {
            getline(f, s);
            n = s.find(" ", 0);
            // 这里使用了string类的find方法，该方法有两个参数，第一个参数是要查找的字符串或字符，这里是一个空格符号，第二个参数表示从哪个位置开始查找，这里是从0位置开始。
            s1 = s.substr(0, n);
            // 这是一个字符串操作，用于截取字符串s中下标从0到n-1的子串，并将其赋值给字符串变量s1。
            // 具体来说，这里使用了string类的substr方法，该方法有两个参数，第一个参数表示开始截取的位置，这里是从0位置开始；第二个参数表示截
            // 取的长度，这里是从0位置开始一直截取到第一个空格的位置（即n-1）。
            // 执行完该语句后，s1变量将保存了字符串s中第一个空格之前的所有字符（也就是第一个单词）。
            a.insert(pair<string, string>(s1, s));
            if (f.eof())
                break;
        }
    }
    ~test() { f.close(); }
    void FIND()
    {
        string word;
        cout << "input word:";
        cin >> word;
        p = a.find(word);
        if (p != a.end())
        {
            cout << p->second << endl;
        }
        else
            cout << "no word!" << endl;
    }
};
int main()
{
    test t;
    t.FIND();
    return 0;
}

// 类模板和模板类是两个不同的概念。

// 一个类模板是指定义一个通用的类，其中至少有一个类型参数。这个类型参数可以在使用时被特化为具体的类型，使得该类能够适应各种数据类型。例如：

// template <typename T>
// class MyClass {
//     // Class definition using type parameter T
// };
// 这里的 MyClass 是一个类模板，它的类型参数是 T。

// 另一方面，模板类是指使用类模板创建的特定类型。当我们使用类模板时，实际上是在创建模板类的实例。例如：

// MyClass<int> myIntClass;
// 这里的 MyClass<int> 就是一个模板类，它是由 MyClass 这个类模板通过将类型参数 T 特化为 int 得到的。

// 因此，类模板和模板类是密切相关的概念，但它们并不是同一回事。类模板是一个通用的模板，而模板类则是由类模板实例化得到的具体类型。

// 在常量成员函数中，除了成员变量之外，任何其他的变量（包括局部变量和参数）都可以被修改。因此，在常量成员函数中可以声明和使用新的局部变量，并对
// 它们进行更改，而不会影响对象本身的状态。

// 以下是一个示例代码，说明了在常量成员函数中声明和使用新的局部变量：

// c++
// class MyClass {
// public:
//     int getValue() const {
//         int value = 42;     // 在常量成员函数中定义的局部变量
//         value += 10;        // 修改局部变量的值
//         return value;       // 返回修改后的值
//     }
// private:
//     int m_value;
// };
// 在上面的示例中，getValue()函数是一个常量成员函数，它定义了一个名为value的局部变量，并将其值设置为42。然后，它修改这个局部变量的值并返回修改
// 后的结果。由于这个局部变量是在常量成员函数中声明的，所以即使这个函数是常量成员函数，它仍然可以被修改。

// 需要注意的是，虽然常量成员函数允许对局部变量进行更改，但是它不能修改任何对象的状态，包括成员变量、静态变量等。因此，如果你想要修改对象的状态
// ，必须使用非常量成员函数。