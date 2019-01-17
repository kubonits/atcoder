#include<cstdio>
#define mod 1000000007
using namespace std;
int main(){
    int t,dp[301][601]={},a[300],ans=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&a[i]);
    }
    dp[0][0]=1;
    for(int i=0;i<t;i++){
        for(int j=0;j<=a[i];j++){
            for(int k=0;k<=300;k++){
                dp[i+1][j+k]+=dp[i][k*2];
                dp[i+1][j+k]%=mod;
            }
        }
    }
    for(int i=1;i<=t;i++){
        ans+=dp[i][1];
        ans%=mod;
    }
    for(int i=2;i<=600;i*=2){
        ans+=dp[t][i];
        ans%=mod;
    }
    printf("%d\n",ans);
}