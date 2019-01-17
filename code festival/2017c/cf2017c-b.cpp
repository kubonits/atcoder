#include<cstdio>
using namespace std;

int n,ans=0,a[10],b[10];

int solve(int p){
    if(p==n){
        for(int i=0;i<n;i++){
            if(b[i]%2==0){
                return 1;
            }
        }
        return 0;
    }
    int ans=0;
    for(int i=-1;i<=1;i++){
        b[p]=a[p]+i;
        ans+=solve(p+1);
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    ans=solve(0);
    printf("%d\n",ans);
}