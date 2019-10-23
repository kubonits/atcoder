#include<cstdio>
using namespace std;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(n*(n-1)/2-(n-1)<k){
        printf("-1\n");
    }
    else{
        printf("%d\n",n*(n-1)/2-k);
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(i==1||!k){
                    printf("%d %d\n",i,j);
                }
                else{
                    k--;
                }
            }
        }
    }
}