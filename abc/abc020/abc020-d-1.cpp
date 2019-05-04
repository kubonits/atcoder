#include<cstdio>
#define mod 1000000007
typedef long long ll;
using namespace std;
ll gcd(ll x,ll y){
    if(y==0){
        return x;
    }
    else{
        return gcd(y,x%y);
    }
}
int main(){
    ll n,k,ans=0,g,x;
    scanf("%lld %lld",&n,&k);
    for(ll i=1LL;i<=n;i++){
        g=gcd(i,k);
        x=i*k/g;
        x%=mod;
        ans+=x;
        ans%=mod;
    }
    printf("%lld\n",ans);
}