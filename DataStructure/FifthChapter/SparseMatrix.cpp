#define MAX_SIZE 12500
typedef int ElemType;

typedef struct
{
    int i, j;
    ElemType e;
} Triple;

typedef struct {
    Triple data[MAX_SIZE+1];
    int mu,nu,tu;

}TsMatrix;