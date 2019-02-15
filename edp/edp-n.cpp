#include<cstdio>
#include<algorithm>
#define INF 1000000000000000000
using namespace std;
int main(){
    int n;
    long long a[400],sum[401]={},dp[400][400]={};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        sum[i+1]=sum[i]+a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j+i<n;j++){
            dp[j][i+j]=INF;
            for(int k=j;k<i+j;k++){
                dp[j][i+j]=min(dp[j][i+j],dp[j][k]+dp[k+1][i+j]);
            }
            dp[j][i+j]+=sum[i+j+1]-sum[j];
        }
    }
    printf("%lld\n",dp[0][n-1]);
}