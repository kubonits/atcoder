#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#define MAX_V 100002
#define INF 1000000000
using namespace std;
struct edge {
  int to;
  long cost;
};
typedef pair<int, int> P;

int V;
vector<edge> G[MAX_V];
long d[MAX_V];

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d + V + 1, INF);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main() {
  int m, r, t, a, b;
  long c, ans = 0;
  scanf("%d%d%d%d", &V, &m, &r, &t);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%ld", &a, &b, &c);
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }
  for (int i = 1; i <= V; i++) {
    dijkstra(i);
    d[0] = INF;
    sort(d, d + V + 1);
    int left = 1;
    int right = 1;
    while (left < V && right < V) {
      if (d[left] * r < d[right] * t) {
        ans += (long)(V - right);
        left++;
      } else {
        right++;
      }
    }
    if (t > r) {
      ans -= (long)(V - 1);
    }
  }
  printf("%ld\n", ans);
}