#include <algorithm>
#include <cmath>
#include <cstring>
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
#define MAX_V 200001
#define INF 1000000000000000
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
struct edge {
  ll to;
  ll cost;
  ll k;
};

ll V;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(ll s) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d + V + 1, INF);
  d[s] = 0LL;
  que.push(P(0LL, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] > (d[v] + e.k - 1LL) / e.k * e.k + e.cost) {
        d[e.to] = (d[v] + e.k - 1LL) / e.k * e.k + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main() {
  ll n, m, x, y, a, b, t, k;
  cin >> n >> m >> x >> y;
  V = n;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> t >> k;
    G[a].push_back({b, t, k});
    G[b].push_back({a, t, k});
  }
  dijkstra(x);
  cout << (d[y] != INF ? d[y] : -1) << endl;
}
