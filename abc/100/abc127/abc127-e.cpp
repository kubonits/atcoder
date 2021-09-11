#include<cstdio>
#include<algorithm>
#define mod 1000000007
using namespace std;
typedef long long ll;

ll kai[200001],inv[200001],sum[200001];
ll n,m,k,ans;

ll gyaku(ll x){
    ll res=x;
    ll a=mod-2;
    for(int i=1;i<30;i++){
        x=x*x;
        x%=mod;
        if(((1<<i)&a)){
            res*=x;
            res%=mod;
        }
    }
    return res;
}

void kaiinit(){
    kai[0]=kai[1]=1LL;
    for(ll i=2;i<=n*m;i++){
        kai[i]=kai[i-1]*i;
        kai[i]%=mod;
    }
    inv[n*m]=gyaku(kai[n*m]);
    for(ll i=n*m-1;i>=0;i--){
        inv[i]=inv[i+1]*(i+1LL);
        inv[i]%=mod;
    }
}
int main(){
    scanf("%lld %lld %lld",&n,&m,&k); 
    for(ll i=1;i<=200000;i++){
        sum[i]=sum[i-1]+i;
        sum[i]%=mod;
    }
    for(ll i=0;i<m;i++){
        ans+=(sum[m-i-1])*n*n;
        ans%=mod;
    }
    for(ll i=0;i<n;i++){
        ans+=(sum[n-i-1])*m*m;
        ans%=mod;
    }
    if(k!=2){
        kaiinit();
        ans*=kai[n*m-2];
        ans%=mod;
        ans*=inv[k-2];
        ans%=mod;
        ans*=inv[n*m-k];
        ans%=mod;
    }
    printf("%lld\n",ans);
}