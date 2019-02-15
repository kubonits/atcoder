#include<cstdio>

using namespace std;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(k*2-1<=n){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}