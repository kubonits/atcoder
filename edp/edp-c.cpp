#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,dp[100000][3]={},a,b,c,ans;
    scanf("%d",&n);
    scanf("%d %d %d",&a,&b,&c);
    dp[0][0]=a;
    dp[0][1]=b;
    dp[0][2]=c;
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&a,&b,&c);
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a;
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+b;
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+c;
    }
    ans=max(dp[n-1][0],dp[n-1][1]);
    ans=max(ans,dp[n-1][2]);
    printf("%d\n",ans);
}