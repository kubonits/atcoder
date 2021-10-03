#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll kai[3000],inv[3000];
int n,k;
ll mod_pow( ll x,ll n,ll mod){
    ll res=1;
    while(n>0){
        if(n&1){
            res=res*x%mod;
        }
        x=x*x%mod;
        n/=2;
    }
    return res;
}
void init(){
    kai[0]=1LL;
    for(ll i=1LL;i<=2500;i++){
        kai[i]=kai[i-1]*i;
        kai[i]%=MOD;
    }
    inv[2500]=mod_pow(kai[2500],MOD-2LL,MOD);
    for(ll i=2499;i>=0;i--){
        inv[i]=inv[i+1]*(i+1);
        inv[i]%=MOD;
    }
}
int main(){
    ll ans;
    scanf("%d %d",&n,&k);
    init();
    for(ll i=1;i<=k;i++){
        ans=1LL;
        ans*=kai[k-1];
        ans%=MOD;
        ans*=inv[i-1];
        ans%=MOD;
        ans*=inv[k-i];
        ans%=MOD;
        ans*=kai[n-k+1];
        ans%=MOD;
        ans*=inv[i];
        ans%=MOD;
        if(n-k+1-i>=0){
            ans*=inv[n-k+1-i];
            ans%=MOD;
            printf("%lld\n",ans);
        }
        else{
            printf("0\n");
        }
    }
}