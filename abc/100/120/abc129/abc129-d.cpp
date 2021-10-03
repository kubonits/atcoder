#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
#include<queue>
#define mod 1000000007
#define INF 1000000000000000
using namespace std;
int h,w;
char s[2010][2010];
int dp[4][2010][2010],ans;
int main(){
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='#'){
                dp[0][i][j]=i;
                dp[2][i][j]=j;
            }
            else{
                if(i){
                    dp[0][i][j]=dp[0][i-1][j];
                }
                else{
                    dp[0][i][j]=-1;
                }
                if(j){
                    dp[2][i][j]=dp[2][i][j-1];
                }
                else{
                    dp[2][i][j]=-1;
                }
            }
        }
    }
    for(int i=h-1;i>=0;i--){
        for(int j=w-1;j>=0;j--){
            if(s[i][j]=='#'){
                dp[1][i][j]=i-1;
                dp[3][i][j]=j-1;
            }
            else{
                if(i!=h-1){
                    dp[1][i][j]=dp[1][i+1][j];
                }
                else{
                    dp[1][i][j]=h-1;
                }
                if(j!=w-1){
                    dp[3][i][j]=dp[3][i][j+1];
                }
                else{
                    dp[3][i][j]=w-1;
                }
            }
        }
    }
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='.'){
                ans=max(ans,dp[1][i][j]-dp[0][i][j]+dp[3][i][j]-dp[2][i][j]-1);
            }
        }
    }
    printf("%d\n",ans);
}