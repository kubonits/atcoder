#include<cstdio>
#define mod 1000000007
using namespace std;
int h,w;
long dp[1001][1001]={};
char s[1001][1001];
int main(){
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    dp[1][0]=1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='.'){
                dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j];
                dp[i+1][j+1]%=mod;
            }
        }
    }
    printf("%d\n",dp[h][w]);
}