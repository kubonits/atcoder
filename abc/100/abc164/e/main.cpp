#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define MAX_V 300001
#define INF 1000000000000000
using namespace std;
typedef long long ll;
struct edge {
  int to;
  ll cost;
  int coin;
};
typedef pair<ll, int> P;

int V;
vector<edge> G[MAX_V];
ll d[MAX_V], c[50], dd[50];

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    int from = v;
    int vv = v % 5001;
    v = v / 5001;
    if (d[from] < p.first) continue;
    int to;
    to = 5001 * v + min(5000LL, vv + c[v]);
    if (d[to] > d[from] + dd[v]) {
      d[to] = d[from] + dd[v];
      que.push(P(d[to], to));
    }
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (vv - e.coin >= 0 && d[e.to * 5001 + vv - e.coin] > d[from] + e.cost) {
        d[e.to * 5001 + vv - e.coin] = d[from] + e.cost;
        que.push(P(d[e.to * 5001 + vv - e.coin], e.to * 5001 + vv - e.coin));
      }
    }
  }
}
#define MOD 1000000007
using namespace std;

int main() {
  int n, m, s, a, u, v;
  ll b;
  cin >> n >> m >> s;
  V = n * 5001;
  s = min(s, 5000);
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> a >> b;
    u--;
    v--;
    G[u].push_back({v, b, a});
    G[v].push_back({u, b, a});
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i] >> dd[i];
  }
  dijkstra(s);
  for (int i = 1; i < n; i++) {
    ll ans = 10000000000000000;
    for (int j = 0; j <= 5000; j++) {
      ans = min(ans, d[i * 5001 + j]);
    }
    cout << ans << endl;
  }
}