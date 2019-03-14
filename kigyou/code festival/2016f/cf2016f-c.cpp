#include<cstdio>
#include<vector>
using namespace std;
int n,m,k,l,visit[200001];
vector<int> g[200001];

void dfs(int x){
    visit[x]=1;
    for(int i=0;i<g[x].size();i++){
        if(visit[g[x][i]]==0){
            dfs(g[x][i]);
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            scanf("%d",&l);
            g[i].push_back(n+l);
            g[n+l].push_back(i);
        }
    }
    dfs(0);
    int flag=1;
    for(int i=0;i<n;i++){
        flag*=visit[i];
    }
    if(flag){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}