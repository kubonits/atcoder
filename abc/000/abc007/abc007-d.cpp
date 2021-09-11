#include<cstdio>
using namespace std;
typedef long long ll;

ll ten[19],dp[19],c[10];

ll f(ll x){
    ll res=0;
    if(x<4){
        return 0;
    }
    if(x<9){
        return 1;
    }
    if(x==9){
        return 2;
    }
    int a;
    for(int i=18;i>=0;i--){
        if(x>=ten[i]){
            a=i;
            break;
        }
    }
    if(x/ten[a]==4||x/ten[a]==9){
        res=x%ten[a];
        res++;
    }
    else{
        res=f(x%ten[a]);
    }
    res+=c[x/ten[a]]*dp[a];
    if(x/ten[a]>4){
        res+=ten[a];
    }
    return res;
}

int main(){
    ll a,b;
    ten[0]=1;
    dp[0]=-1;
    c[0]=0;
    for(int i=1;i<10;i++){
        c[i]=c[i-1];
        if(i-1!=4&&i-1!=9){
            c[i]++;
        }
    }
    for(int i=1;i<19;i++){
        ten[i]=ten[i-1]*10;
    }
    dp[1]=2;
    for(int i=2;i<19;i++){
        dp[i]=ten[i-1]*2+8*dp[i-1];
    }
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",f(b)-f(a-1));
}