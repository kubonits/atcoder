#include<cstdio>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
int n,v,u;
ll w,dis[100001];
vector<pair<int,int> > g[100001];

void dfs(int x,int y){
    for(int i=0;i<g[x].size();i++){
        if(g[x][i].first!=y){
            dis[g[x][i].first]=g[x][i].second+dis[x];
            dfs(g[x][i].first,x);
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d %d %lld",&v,&u,&w);
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        printf("%lld\n",dis[i]%2);
    }
}