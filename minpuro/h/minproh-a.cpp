#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 200010
using namespace std;
int n,dp[100010][6];
char s[100010],t[6];
int main(){
    strcpy(t,"yahoo");
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=5;j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }
            else{
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                if(s[i-1]==t[j-1]){
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                }
                else{
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
        for(int j=0;j<=5;j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=min(dp[i][j],dp[i][5]);
            }
            else{
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                if(s[i-1]==t[j-1]){
                    //printf("a\n");
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                }
                else{
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
                }
            }
            //printf("%d ",dp[i][j]);
        }//printf("\n");
    }
    printf("%d\n",min(dp[n][0],dp[n][5]));
}