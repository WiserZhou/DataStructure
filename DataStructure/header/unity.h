#pragma once

// 头文件内容

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
typedef int SElemType;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) <= (b))

typedef enum
{
    DG,  // 有向图 directed graph
    DN,  // 有向网 directed network
    UDG, // 无向图 undirected graph
    UDN  // 无向网 undirected network
} GraphKind;