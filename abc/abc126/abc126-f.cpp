#include<cstdio>
using namespace std;
int main(){
    int n,k,x,y=0;
    scanf("%d %d",&n,&k);
    x=(1<<n);
    if(n==1&&1==0){
        printf("1 1 0 0\n");
        return 0;
    }
    if(x<=k||(n==1&&k==1)){
        printf("-1\n");
    }
    else{
        printf("%d ",k);
        for(int i=0;i<x;i++){
            if(i!=k){
                printf("%d ",i);
            }
        }
        printf("%d ",k);
        for(int i=x-1;i>=0;i--){
            if(k!=i){
                printf("%d ",i);
            }
        }
        printf("\n");
    }
}
