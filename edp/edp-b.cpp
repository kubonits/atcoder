#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int n,dp[200001],h[200000],k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<=n;i++){
        dp[i]=1000000001;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    dp[1]=0;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=k&&i+j<=n;j++){
            dp[i+j]=min(dp[i+j],dp[i]+abs(h[i+j-1]-h[i-1]));
        }
    }
    printf("%d\n",dp[n]);
}