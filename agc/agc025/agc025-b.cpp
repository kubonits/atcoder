#include<cstdio>
#define mod 998244353
using namespace std;

long calc(long x){
    long powx[30],pow2[30],ans=1;
    pow2[0]=1;
    powx[0]=x;
    ans=x;
    for(int i=1;i<30;i++){
        pow2[i]=pow2[i-1]*2;
        powx[i]=powx[i-1]*powx[i-1];
        powx[i]%=mod;
        if((mod-2)&pow2[i]){
            ans*=powx[i];
            ans%=mod;
        }
    }
    return ans;
}

long kai[300001],inv[300001];
int main(){
    long n,a,b,k,ans=0,x;
    kai[0]=inv[0]=1;
    scanf("%ld %ld %ld %ld",&n,&a,&b,&k);
    for(long i=1;i<=n;i++){
        kai[i]=kai[i-1]*i;
        kai[i]%=mod;
    }
    inv[n]=calc(kai[n]);
    for(long i=n-1;i>=1;i--){
        inv[i]=inv[i+1]*(i+1);
        inv[i]%=mod;
    }
    for(long i=0;i<=n;i++){
        if((k-a*i)%b==0&&(k-a*i)/b>=0&&(k-a*i)/b<=n){
            x=kai[n];
            x*=inv[n-i];
            x%=mod;
            x*=inv[i];
            x%=mod;
            x*=kai[n];
            x%=mod;
            x*=inv[n-(k-a*i)/b];
            x%=mod;
            x*=inv[(k-a*i)/b];
            x%=mod;
            ans+=x;
            ans%=mod;
        }
    }
    printf("%ld\n",ans);
}