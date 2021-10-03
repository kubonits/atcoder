#include<cstdio>
#include<utility>
typedef long long ll;
using namespace std;
pair<ll ,ll> e[100000];
ll g[100001];
ll s[100001];
ll ans[100001];

ll dfs(ll a){
    if(a==g[a]){
        return a;
    }
    g[a]=dfs(g[a]);
    return g[a];
}

int main(){
    ll n,m,a,b,l,r;
    scanf("%lld %lld",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%lld %lld",&a,&b);
        e[i]=make_pair(a,b);
    }
    for(int i=0;i<=n;i++){
        g[i]=i;
        s[i]=1;
    }
    ans[m]=(ll)(n*(n-1))/2;
    for(int i=m-1;i>=0;i--){
        ans[i]=ans[i+1];
        l=dfs(e[i].first);
        r=dfs(e[i].second);
        if(l!=r){
            ans[i]+=(s[l]*(s[l]+1))/2;
            ans[i]+=(s[r]*(s[r]+1))/2;
            if(l<r){
                s[l]+=s[r];
                g[r]=l;
                ans[i]-=(s[l]*(s[l]+1))/2;
            }
            else{
                s[r]+=s[l];
                g[l]=r;
                ans[i]-=(s[r]*(s[r]+1))/2;
            }
        }
    }
    for(int i=1;i<=m;i++){
        printf("%lld\n",ans[i]);
    }
}