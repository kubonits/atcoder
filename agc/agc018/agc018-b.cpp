#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[300][300],f[301],ans=300;
void solve(){
    int cnt[301]={},p,q=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(f[a[i][j]]==0){
                cnt[a[i][j]]++;
                break;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(cnt[i]>q){
            p=i;
            q=cnt[i];
        }
    }
    f[p]=1;
    ans=min(ans,q);
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        solve();
    }
    printf("%d\n",ans);
}