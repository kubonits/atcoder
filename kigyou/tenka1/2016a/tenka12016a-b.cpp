#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,p,parent[1001],g[1001][1001]={},b,c[1001],cap[1000][1000],depth[1000],ans;
vector<int> v[1000];

int dfs(int x,int y){
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]!=y){
            if(x==0){
                g[x][v[x][i]]=cap[v[x][i]][x];
            }
            else if(x==0||cap[v[x][i]][x]!=cap[x][parent[x]]){
                g[x][v[x][i]]=cap[v[x][i]][x]-cap[x][parent[x]];
            }
            dfs(v[x][i],x);
        }
    }
    return 0;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<n;i++){
        scanf("%d",&p);
        parent[i]=p;
        v[i].push_back(p);
        v[p].push_back(i);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cap[i][j]=100001;
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d",&b);
        scanf("%d",&c[b]);
        p=b;
        while(p){
            cap[p][parent[p]]=min(cap[p][parent[p]],c[b]);
            p=parent[p];
        }
    }
    dfs(0,-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans+=g[i][j];
        }
    }
    printf("%d\n",ans);
}