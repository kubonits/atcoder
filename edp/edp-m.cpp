#include<cstdio>
#include<algorithm>
#define mod 1000000007
using namespace std;
long long dp[101][100001]={},a[100],sum[100002]={};
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k+1;j++){
            sum[j]=sum[j-1]+dp[i-1][j-1];
        }
        for(int j=0;j<=k;j++){
            dp[i][j]=sum[j+1]-sum[max(0LL,(long long)j-a[i-1])];
            dp[i][j]%=mod;
        }
    }
    printf("%lld\n",dp[n][k]);
}