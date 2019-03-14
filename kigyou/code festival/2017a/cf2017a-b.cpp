#include<cstdio>
using namespace std;
int main(){
    int n,m,k,flag=0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i*(m-j)+j*(n-i)==k){
                flag=1;
            }
        }
    }
    if(flag){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}