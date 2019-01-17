#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> g[100001];
int iri[100001],l[100001],visit[100001];

int dfs(int x){
    visit[x]=1;
    for(int i=0;i<g[x].size();i++){
        iri[g[x][i]]--;
        l[g[x][i]]=max(l[g[x][i]],l[x]+1);
        if(iri[g[x][i]]==0){
            dfs(g[x][i]);
        }
    }
    return 0;
}

int main(){
    int n,m,x,y,ans=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        iri[y]++;
    }
    for(int i=1;i<=n;i++){
        if(iri[i]==0&&visit[i]==0){
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,l[i]);
    }
    printf("%d\n",ans);
}