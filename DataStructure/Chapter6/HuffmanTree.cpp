#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_VERTEX_NUM = 10;

typedef struct Huffman
{
    int parent;
    int left;
    int right;
    char vertex;
    int frequency;
    Huffman(char c, int f) : vertex(c), frequency(f), parent(0), left(0), right(0) {}
    Huffman(char c, int f, int left, int right) : vertex(c), frequency(f), parent(0), left(left), right(right) {}
} Huffman;

