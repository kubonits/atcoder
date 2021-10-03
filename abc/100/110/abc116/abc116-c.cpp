#include<cstdio>
using namespace std;

int n,h[100];
int dfs(int l,int r,int x){
    if(l>r){
        return 0;
    }
    int p=0,a=10000;
    for(int i=l;i<=r;i++){
        if(a>h[i]){
            a=h[i];
            p=i;
        }
    }
    return a-x+dfs(l,p-1,a)+dfs(p+1,r,a);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    printf("%d\n",dfs(0,n-1,0));
}