// #include<iostream>
// #include<cstdio>
// #include<ctime>
// #include<cmath>
// using namespace std;

// const int MAX_Number =10000;  // 多项式最大项数，即多项式阶数+1
// const int MAX_Time=1e3;  // 被测函数最大重复调用次数
// const double CLOCKS_PER_SECOND=((clock_t)1000); 
// // CLOCKS_PER_SECOND 这个常量表示每一秒 有多少个时钟计时单元
// const double CLOCKS_PER_MILLISECOND=((clock_t)1);
// // CLOCKS_PER_MILLISECOND 这个常量表示每毫秒 有多少个始终计时单元

// clock_t startTime;
// clock_t endTime;
// double duration; //  (平均)运行时间

// // 朴素算法
// double f1(int n,double a[],double x)
// {
//     int i;
//     double p=a[0];
//     for ( i =1;i <=n ; i++)
//     {
//         p+=(a[i]*pow(x,i));
//     }
// return p;
// }

// // 秦九韶算法
// double f2(int n,double a[],double x)
// {
//     int i;
//     double p=a[n];
//     for(i=n;i>0;i--)
//     {
//         p=p*x+a[i-1];
//     }
//     return p;
// }

// // 让被测函数重复运行充分多次，使得测出的总的时钟打点间隔充分长，最后计算平均每次运行的时间
// int main()
// {
//     int i;
//     double a[MAX_Number];// 存储多项式系数
//     for(int i=0;i<MAX_Number;i++)// 赋值多项式系数
//     {
//         a[i]=(double)i;
//     }

//     startTime=clock();
//     for(int i=0;i<MAX_Time;i++)// 重复调用函数以获得充分多的时钟打点数
//     {
//         f1(MAX_Number-1,a,1.1);
//     }
//     endTime=clock();
//     duration=(double)(endTime-startTime)/CLOCKS_PER_SECOND/MAX_Time;
//     printf("duration1=%0.10lf s\n",duration);

//     startTime=clock();
//     for(int i=0;i<MAX_Time;i++)
//     {
//         f2(MAX_Number-1,a,1.1);
//     }
//     endTime=clock();
//     duration=(double)(endTime-startTime)/CLOCKS_PER_SECOND/MAX_Time;
//     printf("duration2=%.10lf s\n",duration);
// }


// 求最大子列和问题（分治法）
#include <iostream>
using namespace std;
int maxTri(int a, int b, int c)
{
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}
int maxSum(int data[], int first, int end)
{
    if (first == end)
        return data[first];
    int mid = (first + end) / 2;
    int sumLeft = maxSum(data, first, mid);
    int sumRight = maxSum(data, mid + 1, end);

    int sum1 = 0, left = 0;
    for (int i = mid; i >= first; i--)
    {
        left += data[i];
        if (left > sum1)
            sum1 = left;
    }
    int sum2 = 0, right = 0;
    for (int i = mid + 1; i <= end; i++)
    {
        right += data[i];
        if (right > sum2)
            sum2 = right;
    }
    int sum = sum1 + sum2;

    return maxTri(sum, sumLeft, sumRight);
}

int main()
{
    int data[] = {-1, 3, -2, 4, -6, 1, 6, -1};
    printf("max value: %d", maxSum(data, 0, sizeof(data) / sizeof(int) - 1));
    return 0;
}