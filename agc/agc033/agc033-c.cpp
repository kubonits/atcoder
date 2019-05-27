#include<cstdio>
#include<vector>
using namespace std;

int n,a,b,dis[200001],p,l;
vector<int> v[200001];

void dfs(int x,int y){
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]!=y){
            dis[v[x][i]]=dis[x]+1;
            dfs(v[x][i],x);
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dis[1]=0;
    dfs(1,-1);
    p=1;
    l=0;
    for(int i=1;i<=n;i++){
        if(l<dis[i]){
            l=dis[i];
            p=i;
        }
    }
    dis[p]=0;
    dfs(p,-1);
    for(int i=1;i<=n;i++){
        if(l<dis[i]){
            l=dis[i];
        }
    }
    if(l%3!=1){
        printf("First\n");
    }
    else{
        printf("Second\n");
    }
}