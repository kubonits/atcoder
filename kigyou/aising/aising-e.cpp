#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 100000000000000
using namespace std;

int n,u,v,cnt[5001];
long long a[5001],dp[5001][5001][2],dp2[5000][5001][2];
vector<int> g[5001];
vector<int> child[5001];
void dfs(int x,int y){
    cnt[x]++;
    for(int i=0;i<g[x].size();i++){
        if(g[x][i]!=y){
            dfs(g[x][i],x);
            child[x].push_back(g[x][i]);
        }
    }
    for(int i=0;i<=child[x].size();i++){
        for(int j=0;j<=5000;j++){
            dp2[i][j][0]=INF;
            dp2[i][j][1]=INF;
        }
    }
    if(a[x]>0){
        dp2[0][1][0]=a[x];
        dp2[0][1][1]=a[x];
    }
    else{
        dp2[0][1][0]=INF;
        dp2[0][1][1]=a[x];
    }
    for(int i=0;i<child[x].size();i++){
        for(int j=1;j<=cnt[x];j++){
            for(int k=1;k<=cnt[child[x][i]];k++){
                if(a[x]>0){
                    dp2[i+1][j+k-1][0]=min(dp2[i+1][j+k-1][0],dp2[i][j][0]+dp[child[x][i]][k][0]);
                }
                if((dp[child[x][i]][k][0]!=INF||dp[child[x][i]][k][1]<0)){
                    dp2[i+1][j+k][0]=min(dp2[i+1][j+k][0],dp2[i][j][0]);
                    dp2[i+1][j+k][1]=min(dp2[i+1][j+k][1],dp2[i][j][1]);
                }
                dp2[i+1][j+k-1][1]=min(dp2[i+1][j+k-1][1],dp2[i][j][1]+dp[child[x][i]][k][1]);
            }
        }
        cnt[x]+=cnt[child[x][i]];
    }
    for(int i=0;i<=cnt[x];i++){
        dp[x][i][0]=dp2[child[x].size()][i][0];
        dp[x][i][1]=dp2[child[x].size()][i][1];
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i+1]);
    }
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    for(int i=0;i<n;i++){
        if(dp[1][i+1][0]!=INF||dp[1][i+1][1]<0){
            printf("%d\n",i);
            return 0;
        }
    }
}