#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
typedef long long ll;
int main(){
    ll l,r,ans=2019;
    scanf("%lld %lld",&l,&r);
    for(ll i=l;i<=min(l+2019,r);i++){
        for(ll j=i+1LL;j<=min(l+2019,r);j++){
            ans=min(ans,i*j%2019);
        }
    }
    printf("%lld\n",ans);
}