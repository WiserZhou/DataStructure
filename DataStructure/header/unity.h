
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

template <typename T>
T maxTri(T a, T b, T c)
{
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}
#define LIST_INCREMENT 10
#define LIST_INIT_SIZE 100
#define OVERFLOW -2
#define ERROR 0
#define UNDERFLOW -3

#define OK 1
#define TRUE 1
#define FALSE 0
#define NONE 0
// typedef int ElemType;
typedef int Status;
typedef int Position;
typedef int LEN;
