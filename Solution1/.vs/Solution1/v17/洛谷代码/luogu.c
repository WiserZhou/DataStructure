#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>
int isPrime(int n)
{
	if (n == 0 || n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
				return 0;
		}
		return 1;
	}
}
int main(){
        for(int i=2;i<=10000;i++){
            if(isPrime(i)==1)
            printf("%d ",i);
        }
        return 0;
}