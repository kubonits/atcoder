#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int k,x;
    scanf("%d %d",&k,&x);
    for(int i=max(-1000000,x-k+1);i<=min(1000000,x+k-1);i++){
        printf("%d ",i);
    }
    printf("\n");
}