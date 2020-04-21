#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#define MAX_V 100001
#define INF 100000000
using namespace std;
struct edge {
  int to;
  long cost;
};
typedef pair<int, int> P;

int V;
vector<edge> G[MAX_V];
long ds[MAX_V], dt[MAX_V];

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(ds, ds + V + 1, INF);
  ds[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (ds[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (ds[e.to] > ds[v] + e.cost) {
        ds[e.to] = ds[v] + e.cost;
        que.push(P(ds[e.to], e.to));
      }
    }
  }
}

void dijkstra2(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(dt, dt + V + 1, INF);
  dt[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (dt[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (dt[e.to] > dt[v] + e.cost) {
        dt[e.to] = dt[v] + e.cost;
        que.push(P(dt[e.to], e.to));
      }
    }
  }
}

int main() {
  int n, m, s, t;
  int x, y;
  long d;
  scanf("%d%d%d%d", &n, &m, &s, &t);
  V = n;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%ld", &x, &y, &d);
    G[x].push_back({y, d});
    G[y].push_back({x, d});
  }
  dijkstra2(t);
  dijkstra(s);
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (ds[i] == dt[i] && ds[i] != INF) {
      ans.push_back(i);
    }
  }
  if (ans.empty()) {
    printf("-1\n");
  } else {
    printf("%d", ans[0]);
  }
}