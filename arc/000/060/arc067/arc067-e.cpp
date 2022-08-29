#include<cstdio>
#define mod 1000000007
typedef long long ll;
using namespace std;

ll dp[1001][1001],kai[1001],inv[1001];

ll gyaku(ll x){
    ll res=1;
    ll y=x;
    for(int i=0;i<30;i++){
        if(((1<<i)&(mod-2))){
            res*=y;
            res%=mod;
        }
        y=y*y;
        y%=mod;
    }
    return res;
}

int main(){
    int n,a,b,c,d;
    ll x,y;
    scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
    kai[0]=1;
    for(int i=1;i<=n;i++){
        kai[i]=kai[i-1]*i;
        kai[i]%=mod;
    }
    inv[n]=gyaku(kai[n]);
    for(int i=n-1;i>=0;i--){
        inv[i]=inv[i+1]*(i+1);
        inv[i]%=mod;
    }
    dp[0][0]=1;
    for(int i=1;i<=b;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            if(i>=a){
                y=1;
                for(int k=1;k<c;k++){
                    y*=inv[i];
                    y%=mod;
                }
                for(int k=c;k<=d&&j-k*i>=0;k++){
                    y*=inv[i];
                    y%=mod;
                    x=dp[i-1][j-i*k]*kai[n-j+i*k];
                    x%=mod;
                    x*=inv[n-j];
                    x%=mod;
                    x*=y;
                    x%=mod;
                    x*=inv[k];
                    x%=mod;
                    dp[i][j]+=x;
                    dp[i][j]%=mod;
                }
            }
        }
    }
    printf("%lld\n",dp[b][n]);
}