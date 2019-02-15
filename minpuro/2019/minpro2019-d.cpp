#include<cstdio>
#include<algorithm>
using namespace std;
long n,a[200000],dp[5][200001],ans;
int main(){
    scanf("%ld",&n);
    for(int i=0;i<n;i++){
        scanf("%ld",&a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            dp[j][i+1]=dp[0][i];
            for(int k=1;k<=j;k++){
                dp[j][i+1]=min(dp[j][i+1],dp[k][i]);
            }
        }
        dp[0][i+1]+=a[i];
        dp[4][i+1]+=a[i];
        dp[2][i+1]+=(a[i]+1)%2;
        if(a[i]==0){
            dp[1][i+1]+=2;
            dp[3][i+1]+=2;
        }
        else{
            dp[1][i+1]+=a[i]%2;
            dp[3][i+1]+=a[i]%2;
        }
    }
    ans=dp[0][n];
    for(int i=1;i<5;i++){
        ans=min(ans,dp[i][n]);
    }
    printf("%ld\n",ans);
}