#include<cstdio>
#include<algorithm>
#define mod 1000000007
typedef long long ll;
using namespace std;
int ka[100],kb[100],n,m,sum[2];
ll dp[2][2][1001][1001],ans,ansa,ansb,wa[1001];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&ka[i]);
        sum[0]+=ka[i];
    }
    for(int i=0;i<m;i++){
        scanf("%d",&kb[i]);
        sum[1]+=kb[i];
    }
    for(int i=0;i<=sum[1];i++){
        dp[0][1][i][i]=1;
    }
    for(int i=0;i<=sum[0];i++){
        dp[1][1][i][i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=sum[1];j++){
            wa[0]=dp[0][i%2][j][0];
            for(int k=1;k<=j;k++){
                wa[k]=wa[k-1]+dp[0][i%2][j][k];
                wa[k]%=mod;
            }
            for(int k=0;j+k<=sum[1];k++){
                if(ka[i]!=ka[i-1]){
                    dp[0][(i+1)%2][j+k][k]=wa[j];
                }
                else{
                    dp[0][(i+1)%2][j+k][k]=wa[min(j,k)];
                }
            }
        }
    }
    for(int i=1;i<m;i++){
        for(int j=0;j<=sum[0];j++){
            wa[0]=dp[1][i%2][j][0];
            for(int k=1;k<=j;k++){
                wa[k]=wa[k-1]+dp[1][i%2][j][k];
                wa[k]%=mod;
            }
            for(int k=0;j+k<=sum[0];k++){
                if(kb[i]!=kb[i-1]){
                    dp[1][(i+1)%2][j+k][k]=wa[j];
                }
                else{
                    dp[1][(i+1)%2][j+k][k]=wa[min(j,k)];
                }
            }
        }
    }
    for(int i=0;i<=sum[1];i++){
        ansa+=dp[0][n%2][sum[1]][i];
        ansa%=mod;
    }
    for(int i=0;i<=sum[0];i++){
        ansb+=dp[1][m%2][sum[0]][i];
        ansb%=mod;
    }
    ans=ansa*ansb;
    ans%=mod;
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=sum[1];j++){
            for(int k=0;k<=j;k++){
                if(dp[0][i][j][k])
                printf("%d %d %d %lld\n",i,j,k,dp[0][i][j][k]);
            }
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=sum[0];j++){
            for(int k=0;k<=j;k++){
                if(dp[1][i][j][k])
                printf("%d %d %d %lld\n",i,j,k,dp[1][i][j][k]);
            }
        }
    }
    printf("%lld %lld\n",ansa,ansb);*/
    printf("%lld\n",ans);
}