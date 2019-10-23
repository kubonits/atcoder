#include<cstdio>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll mod_pow( ll x,ll n,ll mod){
    ll res=1;
    while(n>0){
        if(n&1){
            res=res*x%mod;
        }
        x=x*x%mod;
        n >> 1;
    }
    return res;
}

int main(){
    ll a,b,c,n,x=1LL,y=1LL,inv;
    scanf("%lld %lld %lld %lld",&n,&a,&b,&c);
    inv=mod_pow(100,MOD-2,MOD);
    for(int i=0;i<n;i++){
        
    }
}