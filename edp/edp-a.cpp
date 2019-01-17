#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int n,dp[200001],h[200000];
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        dp[i]=1000000001;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    dp[1]=0;
    for(int i=1;i<=n-2;i++){
        dp[i+1]=min(dp[i+1],dp[i]+abs(h[i]-h[i-1]));
        dp[i+2]=min(dp[i+2],dp[i]+abs(h[i+1]-h[i-1]));
    }
    dp[n]=min(dp[n],dp[n-1]+abs(h[n-2]-h[n-1]));
    printf("%d\n",dp[n]);
}