#include<cstdio>
#define mod 1000000007
using namespace std;
int n,m;
long long x[100000],y[100000],ax=0,ay=0,ans,sx[100001],sy[100001];
int main(){
    
    scanf("%d %d",&n,&m);
    sx[0]=sy[0]=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&x[i]);
        sx[i+1]=sx[i]+x[i];
        sx[i+1]%=mod;
        ax+=x[i]*i-sx[i];
        ax%=mod;
    }
    for(int i=0;i<m;i++){
        scanf("%lld",&y[i]);
        sy[i+1]=sy[i]+y[i];
        sy[i+1]%=mod;
        ay+=y[i]*i-sy[i];
        ay%=mod;
    }
    printf("%lld\n",ax*ay%mod);
}