#include<cstdio>
using namespace std;
int main(){
    int n,m,a,b,ans=0,f[101]={},l,r;
    scanf("%d %d %d %d",&n,&m,&a,&b);
    for(int i=0;i<m;i++){
        scanf("%d %d",&l,&r);
        for(int j=l;j<=r;j++){
            f[j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        ans+=f[i];
    }
    printf("%d\n",ans*a+(n-ans)*b);
}