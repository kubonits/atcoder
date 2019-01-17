#include<cstdio>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX_V 100001
#define INF 1000000000000000
using namespace std;
struct edge{int to;long cost;};
typedef pair<long,int> P;

int V;
vector<edge> G[MAX_V][2];
long d[MAX_V][2];

void dijkstra(int s,int b){
    priority_queue<P,vector<P>,greater<P> > que;
    for(int i=0;i<=V;i++){
        d[i][b]=INF;
    }
    d[s][b]=0;
    que.push(P(0,s));

    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v][b]<p.first) continue;
        for(int i=0;i<G[v][b].size();i++){
            edge e=G[v][b][i];
            if(d[e.to][b]>d[v][b]+e.cost){
                d[e.to][b]=d[v][b]+e.cost;
                que.push(P(d[e.to][b],e.to));
            }
        }
    }
}

int main(){
    int m,s,t,v,u;
    long a,b,ans[100000]={};
    scanf("%d%d%d%d",&V,&m,&s,&t);
    for(int i=0;i<m;i++){
        scanf("%d%d%ld%ld",&v,&u,&a,&b);
        G[u][0].push_back({v,a});
        G[u][1].push_back({v,b});
        G[v][0].push_back({u,a});
        G[v][1].push_back({u,b});
    }
    dijkstra(s,0);
    dijkstra(t,1);
    ans[V]=INF-(d[V][0]+d[V][1]);
    for(int i=V-1;i>=0;i--){
        ans[i]=INF-(d[i][0]+d[i][1]);
        ans[i]=max(ans[i],ans[i+1]);
    }
    for(int i=1;i<=V;i++){
        printf("%ld\n",ans[i]);
    }
}