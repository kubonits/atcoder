#include<cstdio>
using namespace std;
int main(){
    int n,sum[(1<<17)]={};
    n=(1<<17);
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]^i;
        if(i%4==3)
        printf("%d %d\n",i,sum[i]);
    }
    
}