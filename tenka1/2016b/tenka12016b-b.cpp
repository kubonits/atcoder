#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 500
using namespace std;
int n,dp[101][101][101],ans=INF;
int main(){
    
    char s[110];
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                dp[i][j][k]=INF;
            }
        }
    }
    dp[0][0][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            //printf("%d %d\n",i,j);
            for(int k=0;k<=i;k++){
                if(j>i||k>i);
                else{
                    if(i==0) continue;
                    if(s[i-1]=='('){
                        if(j!=0&&k<i){
                            dp[i][j][k]=dp[i-1][j-1][k];
                        }
                        if(j!=n){
                            dp[i][j][i]=min(dp[i][j][i],dp[i-1][j+1][k]+1);
                        }
                    }
                    else{
                        if(j!=n&&k<i){
                            dp[i][j][k]=dp[i-1][j+1][k];
                        }
                        if(j!=0){
                            dp[i][j][i]=min(dp[i][j][i],dp[i-1][j-1][k]+1);
                        }
                    }
                }
                //printf("%d ",dp[i][j][k]);
            }
            //printf("\n");
        }
    }
    ans=dp[n][0][0];
    for(int i=1;i<=n;i++){
        ans=min(ans,i+dp[n][0][i]-1);
    }
    printf("%d\n",ans);
}