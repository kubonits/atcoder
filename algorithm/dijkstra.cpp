#include<cstdio>
#include<utility>
#include<vector>
#include<queue>
#define MAX_V 100001
#define INF 1000000000000000
using namespace std;
struct edge{int to;long cost;};
typedef pair<int,int> P;

int V;
vector<edge> G[MAX_V];
long d[MAX_V];

void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V,INF);
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