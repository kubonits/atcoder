#include<cstdio>
#include<utility>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#define MAX_V 100001
#define INF 100000000000000.0
using namespace std;
struct edge{int to;double cost;};
typedef pair<double,int> P;

int V;
vector<edge> G[MAX_V];
double d[MAX_V];

void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V,INF);
    d[s]=0;
    que.push(P(0.0,s));

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
    int n;
    double x[1002],y[1002],r[1002],dis;
    edge a;
    scanf("%lf %lf %lf %lf",&x[0],&y[0],&x[1],&y[1]);
    scanf("%d",&n);
    r[0]=r[1]=0.0;
    for(int i=0;i<n;i++){
        scanf("%lf %lf %lf",&x[2+i],&y[2+i],&r[2+i]);
    }
    V=n+2;
    for(int i=0;i<V;i++){
        for(int j=i+1;j<V;j++){
            dis=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            a={j,max(0.0,dis-(r[i]+r[j]))};
            G[i].push_back(a);
            a.to=i;
            G[j].push_back(a);
        }
    }
    dijkstra(0);
    printf("%.10f\n",d[1]);
}