#include<cstdio>
#define mod 1000000007
typedef long long ll;
using namespace std;
int n,k;
ll kai[200001],dp[1001][1001],sum,inv[200001];

ll gyaku(ll x){
    ll mod2=mod-2,res;
    res=x;
    for(int i=1;i<30;i++){
        x*=x;
        x%=mod;
        if(mod2&(1<<i)){
            res*=x;
            res%=mod;
        }
    }
    return res;
}

void kaiinit(){
    kai[0]=1;
    for(ll i=1;i<=n+k;i++){
        kai[i]=kai[i-1]*i;
        kai[i]%=mod;
    }
    inv[n+k]=gyaku(kai[n+k]);
    for(ll i=n+k-1;i>=0;i--){
        inv[i]=inv[i+1]*(i+1LL);
        inv[i]%=mod;
    }
}

int main(){
    scanf("%d %d",&n,&k);
    kaiinit();
    ll ans;
    ans=kai[n+k-1];
    ans*=inv[n-1];
    ans%=mod;
    ans*=inv[k];
    ans%=mod;
    printf("%lld\n",ans);
}