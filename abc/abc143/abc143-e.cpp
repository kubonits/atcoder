#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
#include<map>
#include<utility>
using namespace std;

#define MAX_V 100001
#define INF 1000000000000000
using namespace std;
struct edge{int to;int cost;};
typedef pair<pair<int,int>,int> P;

int V;
vector<edge> G[MAX_V];
long d[MAX_V];
pair<int ,int> g[310][310];
int n,m,a,b,l,c,q;
void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    g[s][s]={0,0};
    que.push(P({0,0},s));
    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second;
        if(g[s][v]<p.first) continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            pair<int,int> cc;
            if(g[s][v].second+e.cost<=l){
                cc={g[s][v].first,g[s][v].second+e.cost};
            }
            else{
                cc={g[s][v].first+1,e.cost};
            }
            if(g[s][e.to]>cc||g[s][e.to].first==-1){
                g[s][e.to]=cc;
                que.push(P(cc,e.to));
            }
        }
    }
}


int main(){
    scanf("%d%d%d",&n,&m,&l);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            g[i][j].first=-1;
            g[i][j].second=0;
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(c<=l){
            /*g[a][b].first=l;
            g[a][b].second=l-c;
            g[b][a].first=l;
            g[b][a].second=l-c;*/
            G[a].push_back({b,c});
            G[b].push_back({a,c});
        }
    }
    for(int i=1;i<=n;i++){
        dijkstra(i);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",g[a][b].first);
    }
}