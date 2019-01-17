#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 100000000000000
using namespace std;

int n,u,v,parent[5001],k[5000];
long long a[5001],dp[5001][5001][2],dp2[5000][5001][2];
vector<int> g[5001];
void init(){
    for(int i=0;i<=5000;i++){
        for(int j=0;j<=5000;j++){
            dp[i][j][0]=INF;
            dp[i][j][1]=INF;
            dp[i][j][0]=INF;
            dp[i][j][1]=INF;
        }
    }
}

void dfs2(int x,int y){

}

void dfs(int x,int y){
    int cnt=0;
    parent[x]=y;
    for(int i=0;i<g[x].size();i++){
        if(g[x][i]!=y){
            dfs(g[x][y],x);
        }
    }
    if(a[x]>0){
        dp2[0][1][0]=a[x];
        dp2[0][1][1]=a[x];
    }
    else{
        dp2[0][1][1]=a[x];
        dp2[0][1][0]=INF;
    }
    for(int i=0;i<g[x].size();i++){
        for(int j=1;j<=5000;j++){
            if(j!=1){
                dp2[i+1][j][0]=min(INF,dp2[i][j-1][0]);
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%ld",&a[i+1]);
    }
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init();
    dfs(1,-1);
}