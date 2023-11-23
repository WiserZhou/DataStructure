#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define N 101
int main()
{
   int n;
   char a[N];
   scanf("%d",&n);
   for(int i=0;i<n;i++){
      scanf("%c",&a[i]);
   }
   puts(a);
  return 0;
}
