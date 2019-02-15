#include<cstdio>
using namespace std;
double dp[3000][3000]={},p,ans=0.0;
int main(){
    
    int n;
    scanf("%d",&n);
    dp[0][0]=1.0;
    for(int i=0;i<n;i++){
        scanf("%lf",&p);
        dp[i+1][0]=dp[i][0]*(1-p);
        for(int j=1;j<=n;j++){
            dp[i+1][j]=dp[i][j]*(1-p)+dp[i][j-1]*p;
        }
    }
    for(int i=n/2+1;i<=n;i++){
        ans+=dp[n][i];
    }
    printf("%.10f\n",ans);
}