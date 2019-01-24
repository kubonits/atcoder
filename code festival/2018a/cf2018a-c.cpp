#include<cstdio>
#include<algorithm>
#define mod 1000000007
using namespace std;
int main(){
    int n,k,dp[51][3001][2]={},cnt[50],ans=0;
    long long a[50],two[61];
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    two[0]=1;
    for(int i=1;i<61;i++){
        two[i]=2*two[i-1];
    }
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<61;j++){
            if(a[i-1]/two[j]==0){
                cnt[i-1]=j;
                break;
            }
        }
        for(int j=0;j<=3000;j++){
            for(int k=max(0,j-cnt[i-1]+1);k<=j;k++){
                dp[i][j][0]+=dp[i-1][k][0];
                dp[i][j][0]%=mod;
            }
        }
        for(int j=0;j<=3000;j++){
            if(j-cnt[i-1]>=0){
                dp[i][j][1]+=dp[i-1][j-cnt[i-1]][0];
            }
            for(int k=max(0,j-cnt[i-1]);k<=j;k++){
                dp[i][j][1]+=dp[i-1][k][1];
                dp[i][j][1]%=mod;
            }
        }
    }
    if(k<=3000){
        ans=dp[n][k][0];
    }
    for(int i=0;i<=min(3000,k);i++){
        ans+=dp[n][i][1];
        ans%=mod;
    }
    printf("%d\n",ans);
}