#include<cstdio>
using namespace std;
#define mod 998244353
typedef long long ll;
int main(){
    int n,x[200],y[200],cnt;
    ll c[201]={},two[201],ans;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&x[i],&y[i]);
    }
    two[0]=1;
    for(int i=1;i<=n;i++){
        two[i]=2*two[i-1];
        two[i]%=mod;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cnt=0;
            for(int k=0;k<n;k++){
                if(x[i]*y[j]-y[i]*x[j]+x[j]*y[k]-y[j]*x[k]+x[k]*y[i]-y[k]*x[i]==0){
                    cnt++;
                }
            }
            c[cnt]++;
        }
    }
    ans=two[n];
    ans-=n+1;
    ans+=mod;
    ans%=mod;
    for(ll i=2LL;i<=n;i++){
        c[i]*=2LL;
        c[i]/=i;
        c[i]/=(i-1LL);
        ans-=(two[i]-i-1LL)*c[i];
        ans%=mod;
        ans+=mod;
        ans%=mod;
    }
    printf("%lld\n",ans);
}