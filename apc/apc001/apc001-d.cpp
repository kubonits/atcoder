#include<cstdio>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;
vector<int> g[100000];
priority_queue<ll,vector<ll>,greater<ll> > q;
int n,m,x,y,visit[100000],cnt;
ll a[100000];

ll dfs(int x,int y,ll z){
    if(z>a[x]){
        q.push(z);
        z=a[x];
    }
    else{
        q.push(a[x]);
    }
    visit[x]=1;
    for(int i=0;i<g[x].size();i++){
        if(g[x][i]!=y){
            z=dfs(g[x][i],x,z);
        }
    }
    return z;
}

int main(){
    ll ans=0;
    scanf("%d %d",&n,&m);
    if(n<2*(n-1-m)){
        printf("Impossible\n");
        return 0;
    }
    else if(n-1==m){
        printf("0\n");
        return 0;
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        if(visit[i]==0){
            ans+=dfs(i,-1,10000000000);
            cnt++;
        }
    }
    while(2*(n-1)>2*m+cnt){
        ans+=q.top();
        q.pop();
        cnt++;
    }
    printf("%lld\n",ans);
}