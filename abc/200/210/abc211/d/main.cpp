#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
#include <cstring>

#define MAX_V 200001
#define INF 1000000000000000
using namespace std;
struct edge {
  int to;
  long cost;
};
typedef pair<int, int> P;

int V;
vector<edge> G[MAX_V];
ll d[MAX_V];
ll dp[200001];

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d + V, INF);
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
  int n, m, a, b;
  cin >> n >> m;
  V = n + 1;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    G[a].push_back({b, 1});
    G[b].push_back({a, 1});
  }
  dijkstra(1);
  vector<pair<int, int> > x;
  for (int i = 1; i <= n; i++) {
    x.push_back({d[i], i});
    dp[i] = 0;
  }
  dp[1] = 1;
  sort(x.begin(), x.end());
  for (int i = 0; i < n; i++) {
    int v = x[i].second;
    for (int j = 0; j < G[v].size(); j++) {
      if (d[v] + 1 == d[G[v][j].to]) {
        dp[G[v][j].to] += dp[v];
        dp[G[v][j].to] %= MOD;
      }
    }
  }
  cout << dp[n] << endl;
}