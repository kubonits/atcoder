#include<cstdio>
#define mod 1000000007
using namespace std;
typedef long long ll;

ll kai[200001],inv[200001],b,w;;

ll gyaku(ll x){
    ll mod2=mod-2,res=1LL,y=x;
    res=x;
    for(int i=1;i<30;i++){
        y=y*y;
        y%=mod;
        if(mod2&(1<<i)){
            res*=y;
            res%=mod;
        }
    }
    return res;
}

void kaiinit(){
    kai[0]=1LL;
    for(ll i=1;i<=b+w;i++){
        kai[i]=kai[i-1]*i;
        kai[i]%=mod;
    }
    
}

int main(){
    scanf("%lld %lld",&b,&w);
    kaiinit();
    for(int i=0;i<b+w;i++){

    }
}