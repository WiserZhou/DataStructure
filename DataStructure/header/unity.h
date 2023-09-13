
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

template <typename T>
T maxTri(T a, T b, T c)
{
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

#define LIST_INIT_SIZE 100
#define OVERFLOW -2
#define ERROR 0
#define LIST_INCREMENT 10
#define OK 1
#define TRUE 1
#define FALSE 0
#define NONE 0
// typedef int ElemType;
typedef int Status;
typedef int Position;
typedef int LEN;

#define STACK_INIT_SIZE 10000
#define STACK_INCREMENT 10
#define BINARY 8

typedef struct PosType
{
    int x;
    int y;
} PosType;

typedef struct
{
    int ord;
    PosType seat;
    int di;
} SElemType;
typedef struct
{
    int ord;
    PosType seat;
    int di;
} ElemType;
typedef int QElemType;