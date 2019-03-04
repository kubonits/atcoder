#include<cstdio>
#include<map>
#include<utility>
#include<vector>
#include<queue>
#define INF 1000000
using namespace std;

struct edge{int to;long cost;};
typedef pair<int,int> P;

int V;
vector<edge> G[500000];
long d[500000];

void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V,INF);
    d[s]=0;
    que.push(P(0,s));

    while(!que.empty()){
        P p=que.top(); que.pop();
        //printf("%d %d\n",p.first,p.second);
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
    int n,m,p,q,c,cnt=0;
    edge x;
    map<pair<int,int>,int> ma;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&p,&q,&c);
        decltype(ma)::iterator a=ma.find(make_pair(p,c));
        if(a==ma.end()){
            ma.insert(make_pair(make_pair(p,c),n+cnt));
            x={n+cnt,1};
            G[p-1].push_back(x);
            x={p-1,0};
            G[n+cnt].push_back(x);
            cnt++;
        }
        decltype(ma)::iterator b=ma.find(make_pair(q,c));
        if(b==ma.end()){
            ma.insert(make_pair(make_pair(q,c),n+cnt));
            x={n+cnt,1};
            G[q-1].push_back(x);
            x={q-1,0};
            G[n+cnt].push_back(x);
            cnt++;
        }
        x={ma[make_pair(q,c)],0};
        G[ma[make_pair(p,c)]].push_back(x);
        x={ma[make_pair(p,c)],0};
        G[ma[make_pair(q,c)]].push_back(x);
    }
    V=n+cnt;
    dijkstra(0);
    if(d[n-1]==INF){
        printf("-1\n");
    }
    else{
        printf("%ld\n",d[n-1]);
    }
}