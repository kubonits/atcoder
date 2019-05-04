#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
#define mod 998244353
ll n,a[300],dp[301][90000],ans,sum,s,b,two[301];
vector<ll> v[301];
int main(){
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    two[0]=1;
    for(int i=1;i<=n;i++){
        two[i]=2*two[i-1];
        two[i]%=mod;
    }
    dp[0][0]=1;
    v[0].push_back(0);
    for(int i=0;i<n;i++){
        for(int j=i;j>=0;j--){
            for(int k=0,s=v[j].size();k<s;k++){
                if(dp[j+1][v[j][k]+a[i]]==0){
                    v[j+1].push_back(v[j][k]+a[i]);
                }
                dp[j+1][v[j][k]+a[i]]+=dp[j][v[j][k]];
                dp[j+1][v[j][k]+a[i]]%=mod;
            }
        }
    }
    ans=1;
    for(int i=0;i<n;i++){
        ans*=3;
        ans%=mod;
    }
    for(int i=1;i<=n;i++){
        for(int j=sum/2+sum%2;j<=sum;j++){
            b+=dp[i][j]*two[n-i];
            b%=mod;
        }
    }
    b*=3;
    b%=mod;
    ans+=mod-b;
    ans%=mod;
    if(sum%2==0){
        b=0;
        for(int i=1;i<=n;i++){
            b+=dp[i][sum/2];
        }
        ans+=b*3;
        ans%=mod;
    }
    printf("%lld\n",ans);
}