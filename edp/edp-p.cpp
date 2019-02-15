#include<cstdio>
#include<vector>
#define mod 1000000007
using namespace std;
int n,x,y;
vector<int> g[100001];
long long dp[100001][2];
void dfs(int x,int y){
    dp[x][0]=1;
    dp[x][1]=1;
    for(int i=0;i<g[x].size();i++){
        if(g[x][i]!=y){
            dfs(g[x][i],x);
            dp[x][0]*=(dp[g[x][i]][0]+dp[g[x][i]][1]);
            dp[x][1]*=dp[g[x][i]][0];
            dp[x][0]%=mod;
            dp[x][1]%=mod;
        }
    }
    dp[x][0]%=mod;
    dp[x][1]%=mod;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    printf("%lld\n",(dp[1][0]+dp[1][1])%mod);
}
