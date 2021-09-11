#include<cstdio>
using namespace std;
int n,x,sum[(1<<18)+2],y[1000000];
int main(){
    
    scanf("%d",&n);
    x=(1<<n+1);
    for(int i=0;i<x;i++){
        scanf("%d",&y[i]);
        sum[i+1]=sum[i]^y[i];
    }
    for(int i=0;i<(1<<n);i++){
        int right,left;
        left=0;
        right=x-1;
        while(y[left]!=i){
            left++;
        }
        while(y[right]!=i){
            right--;
        }
        printf("%d %d\n",i,sum[right+1]^sum[left]);
    }
}