#include<cstdio>
#define mod 998244353
typedef long long ll;
using namespace std;

ll n,kai[1001],inv[1001];

ll gyaku(ll x){
    ll res=1LL;
    if((mod-2)&1){
        res*=x;
        res%=mod;
    }
    for(int i=1;i<30;i++){
        x=x*x;
        x%=mod;
        if((mod-2)&(1<<i)){
            res*=x;
            res%=mod;
        }
    }
    return res;
}
ll dp[1002][1001];
void kaiinit(){
    kai[0]=1;
    inv[0]=1;
    for(ll i=1;i<=n;i++){
        kai[i]=kai[i-1]*i;
        kai[i]%=mod;
    }
    inv[n]=gyaku(kai[n]);
    for(ll i=n-1;i>0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
int main(){
    ll a,c[1001]={},num=0,x,y;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a);
        c[a]++;
    }
    kaiinit();
    dp[n+1][0]=1;
    for(int i=n;i>=1;i--){
        for(int j=n;j>=0;j--){
            num=j+c[i];
            y=1LL;
            if(num<=n){
                for(int k=0;num-i*k>=0;k++){
                    x=dp[i+1][j];
                    x*=kai[num];
                    x%=mod;
                    x*=inv[num-i*k];
                    x%=mod;
                    x*=y;
                    x%=mod;
                    x*=inv[k];
                    x%=mod;
                    y*=inv[i];
                    y%=mod;
                    dp[i][num-k*i]+=x;
                    dp[i][num-k*i]%=mod;
                }
            }
        }
    }
    printf("%lld\n",dp[1][0]);
}