#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<cstring>
#define MOD 1000000009
using namespace std;
typedef long long ll;
ll kai[200001],inv[200001];
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
    for(ll i=1LL;i<=200000;i++){
        kai[i]=kai[i-1]*i;
        kai[i]%=MOD;
    }
    inv[200000]=mod_pow(kai[200000],MOD-2LL,MOD);
    for(ll i=199999;i>=0;i--){
        inv[i]=inv[i+1]*(i+1);
        inv[i]%=MOD;
    }
}

ll comb(ll r, ll c){
    ll res;
    res=kai[r];
    res*=inv[c];
    res%=MOD;
    res*=inv[r-c];
    res%=MOD;
    return res;
}
int main(){
    ll dp[50][50][2500]={};
    scanf("%d %d",&n,&k);
    for(int i=1;i<=50;i++){
        dp[0][i][0]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=50;j++){
            //for()
        }
    }
}