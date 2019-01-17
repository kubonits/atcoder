#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int n,dp[100010][2],ans=0;
    char t[100010];
    scanf("%s",t);
    n=strlen(t);
    dp[0][0]=-1;
    dp[0][1]=0;
    for(int i=0;i<n;i++){
        if(t[i]=='?'){
            dp[i+1][0]=dp[i][1]+1;
            dp[i+1][1]=dp[i][0]+1;
        }
        else if(t[i]=='2'){
            dp[i+1][0]=dp[i][1]+1;
            dp[i+1][1]=0;
        }
        else if(t[i]=='5'){
            dp[i+1][0]=-1;
            dp[i+1][1]=dp[i][0]+1;
        }
        else{
            dp[i+1][0]=-1;
            dp[i+1][1]=0;
        }
        ans=max(ans,dp[i+1][0]/2*2);
        ans=max(ans,dp[i+1][1]/2*2);
    }
    printf("%d\n",ans);
}