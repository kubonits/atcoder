#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll dfs(ll x){
    if(x==1){
        return 1LL;
    }
    else if(x%2==0){
        return dfs(x/2);
    }
    return 2LL*dfs(x/2)%MOD;
}

int main(){
    ll ans,l,r;
    scanf("%lld%lld",&l,&r);
    ans=dfs(r);
    printf("%lld\n",ans);
}