#include<cstdio>
#include<algorithm>
#define mod 1000000007
using namespace std;
typedef long long ll;

ll gcd(ll x,ll y){
    if(y==0){
        return x;
    }
    else{
        return gcd(y,x%y);
    }
}

int main(){
    ll n,k,ans=0,g,y,x,z;
    scanf("%lld %lld",&n,&k);
    for(ll i=0;i<k;i++){
        g=gcd(i,k);
        y=n/k*k+i;
        y%=mod;
        z=n/k;
        if(i<=n%k){
            z++;
        }
        if(y>n){
            y-=k;
        }
        x=(i+y)*z/2*(k/g);
        x%=mod;
        ans+=x;
        ans%=mod;
    }
    printf("%lld\n",ans);
}