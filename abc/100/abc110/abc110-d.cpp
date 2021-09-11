#include<cstdio>
#include<cmath>
#include<vector>
#define mod 1000000007
using namespace std;

long calc(long x){
    long t[31],a[31],ans=1;
    t[0]=1;
    a[0]=x;
    ans=x;
    for(int i=1;i<31;i++){
        t[i]=2*t[i-1];
        a[i]=a[i-1]*a[i-1];
        a[i]%=mod;
        if((mod-2)&t[i]){
            ans*=a[i];
            ans%=mod;
        }
    }
    return ans;
}

int main(){
    long n,m,t[100100],inv[100100],s,ans=1;
    vector<long> v;
    scanf("%ld %ld",&n,&m);
    s=sqrt(m);
    t[0]=1;
    for(long i=1;i<=n+30;i++){
        t[i]=t[i-1]*i;
        t[i]%=mod;
    }
    inv[n+30]=calc(t[n+30]);
    for(long i=n+29;i>=0;i--){
        inv[i]=inv[i+1]*(i+1);
        inv[i]%=mod;
    }
    for(long i=2;i<=s;i++){
        if(m%i==0){
            v.push_back(1);
            m/=i;
            while(m%i==0){
                v.back()++;
                m/=i;
            }
        }
    }
    if(m>1){
        v.push_back(1);
    }
    for(long i=0;i<v.size();i++){
        ans*=t[v[i]+n-1];
        ans%=mod;
        ans*=inv[v[i]];
        ans%=mod;
        ans*=inv[n-1];
        ans%=mod;
    }
    printf("%ld\n",ans);
}