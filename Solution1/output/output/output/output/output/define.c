    #include <stdio.h>
    #include <stdlib.h>
    #define N 200001
    int main(){
        int n,a[N]={0};
        scanf("%d",&n);
        for(int i=0;i<n;i++){
                scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]>a[j]){
                    int temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        int b[N]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[j]==i)b[i]++;
            }
            
        }
        if(b[n]==n)printf("%d",n);
        
        return 0;
    }
    
   
