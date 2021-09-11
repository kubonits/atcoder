#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
vector<int> g[200001];
ll score[200001];

void dfs(int v,int pa, ll sum){
    score[v]+=sum;
    for(int i=0;i<g[v].size();i++){
        if(g[v][i]!=pa){
            dfs(g[v][i],v,score[v]);
        }
    }
}
int main(){
    int n,q,a,b,p;
    ll x;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<q;i++){
        scanf("%d %lld",&p,&x);
        score[p]+=x;
    }
    dfs(1,-1,0LL);
    for(int i=1;i<=n;i++){
        printf("%lld ",score[i]);
    }
    printf("\n");
}