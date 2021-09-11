#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#define MAX_V 100001
#define INF 1000000000000000
using namespace std;
typedef long long ll;
struct edge {
  int to;
  ll cost;
};
typedef pair<int, int> P;

int V;
vector<edge> Gto[MAX_V], Gf[MAX_V];
ll dt[MAX_V], df[MAX_V];

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  for (int i = 0; i <= V; i++) {
    dt[i] = INF;
  }
  dt[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (dt[v] < p.first) continue;
    for (int i = 0; i < Gto[v].size(); i++) {
      edge e = Gto[v][i];
      if (dt[e.to] > dt[v] + e.cost) {
        dt[e.to] = dt[v] + e.cost;
        que.push(P(dt[e.to], e.to));
      }
    }
  }
}

void dijkstra2(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  for (int i = 0; i <= V; i++) {
    df[i] = INF;
  }
  df[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (df[v] < p.first) continue;
    for (int i = 0; i < Gf[v].size(); i++) {
      edge e = Gf[v][i];
      if (df[e.to] > df[v] + e.cost) {
        df[e.to] = df[v] + e.cost;
        que.push(P(df[e.to], e.to));
      }
    }
  }
}

int main() {
  int m, x, y;
  ll z, t;
  ll a[100001], ans = 0;
  scanf("%d%d%lld", &V, &m, &t);
  for (int i = 1; i <= V; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%lld", &x, &y, &z);
    Gto[x].push_back({y, z});
    Gf[y].push_back({x, z});
  }
  dijkstra(1);
  dijkstra2(1);
  for (int i = 1; i <= V; i++) {
    if (df[i] != INF && dt[i] != INF) {
      ll T = t - (df[i] + dt[i]);
      ans = max(ans, T * a[i]);
    }
  }
  printf("%lld\n", ans);
}