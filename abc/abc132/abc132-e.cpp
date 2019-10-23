#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define MAX_V 300001
#define INF 1000000000
#define mod 1000000007
using namespace std;

struct edge{int to;long cost;};
typedef pair<int,int> P;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];
int dd[MAX_V];
void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V+1,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

int main(){
    int n,m,v,u,s,t,ans=INF;
    scanf("%d %d",&n,&m);
    V=300000;
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        edge e;
        e.cost=1;
        e.to=v+100000;
        G[u].push_back(e);
        e.to=v+200000;
        G[u+100000].push_back(e);
        e.to=v;
        G[u+200000].push_back(e);
    }
    scanf("%d %d",&s,&t);
    dijkstra(s);
    for(int i=0;i<=n;i++){

    }
    if(d[t]<INF){
        printf("%d\n",d[t]/3);
    }
    else{
        printf("-1\n");
    }
}