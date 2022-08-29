#include<cstdio>
#define mod 1000000007
using namespace std;
long h,w,a,b,g[100000],kai[200001],inv[200001];

long calc(long x){
    long two[32],ans,t[32],y=mod-2;
    two[0]=1;
    ans=t[0]=x;
    for(int i=1;i<32;i++){
        two[i]=2*two[i-1];
        t[i]=t[i-1]*t[i-1];
        t[i]%=mod;
        if(y&two[i]){
            ans*=t[i];
            ans%=mod;
        }
    }
    return ans;
}
int main(){
    long ans=0;
    scanf("%ld %ld %ld %ld",&h,&w,&a,&b);
    kai[0]=kai[1]=inv[0]=inv[1]=1;
    for(long i=2;i<=h+w;i++){
        kai[i]=kai[i-1]*i;
        kai[i]%=mod;
    }
    inv[h+w]=calc(kai[h+w]);
    for(long i=h+w-1;i>1;i--){
        inv[i]=inv[i+1]*(i+1L)%mod;
    }
    for(int i=b;i<w;i++){
        g[i]=kai[i+h-a-1]*inv[i];
        g[i]%=mod;
        g[i]*=inv[h-a-1];
        g[i]%=mod;
        g[i]*=kai[a-1+w-1-i];
        g[i]%=mod;
        g[i]*=inv[w-1-i];
        g[i]%=mod;
        g[i]*=inv[a-1];
        g[i]%=mod;
        ans+=g[i];
        ans%=mod;
    }
    printf("%ld\n",ans);
}
