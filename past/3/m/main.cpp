#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
#define MAX_V 100001
#define INF 1000000000

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
  for (int i = 0; i <= V; i++) {
    d[i] = INF;
  }
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

int dp[(1 << 16)][17];

int main() {
  int n, m, a, b, s, t[16], k, g[17][17];
  cin >> n >> m;
  V = n;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    G[a].push_back({b, 1});
    G[b].push_back({a, 1});
  }
  cin >> s;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> t[i];
  }
  dijkstra(s);
  g[k][k] = 0;
  for (int i = 0; i < k; i++) {
    g[i][k] = g[k][i] = d[t[i]];
  }
  for (int i = 0; i < k; i++) {
    dijkstra(t[i]);
    for (int j = 0; j < k; j++) {
      g[i][j] = g[j][i] = d[t[j]];
    }
  }
  for (int i = 0; i < (1 << k); i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = 1000000000;
    }
  }
  dp[0][k] = 0;
  for (int i = 0; i < (1 << k); i++) {
    for (int j = 0; j <= k; j++) {
      for (int l = 0; l < 16; l++) {
        if ((i & (1 << l)) == 0) {
          dp[i | (1 << l)][l] = min(dp[i | (1 << l)][l], dp[i][j] + g[j][l]);
        }
      }
    }
  }
  int ans = 1000000000;
  for (int i = 0; i < k; i++) {
    ans = min(ans, dp[(1 << k) - 1][i]);
  }
  cout << ans << endl;
}