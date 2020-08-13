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
#define INF 10000
using namespace std;
typedef long long ll;

struct edge {
  int to, cap, rev;
};

vector<edge> g[600010];
bool used[600010];

void add_edge(int from, int to, int cap) {
  g[from].push_back((edge){to, cap, (int)g[to].size()});
  g[to].push_back((edge){from, 0, (int)g[from].size() - 1});
}

int dfs(int v, int t, int f) {
  if (v == t) {
    return f;
  }
  used[v] = true;
  for (int i = 0; i < g[v].size(); i++) {
    edge &e = g[v][i];
    if (!used[e.to] && e.cap > 0) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        g[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s, int t) {
  int flow = 0;
  for (;;) {
    memset(used, 0, sizeof(used));
    int f = dfs(s, t, INF);
    if (f == 0) return flow;
    flow += f;
  }
}

int main() {
  int n, a, b, cnt = 1;
  map<int, int> m;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    add_edge(0, i, 1);
  }
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (m.find(a) == m.end()) {
      m.insert({a, n + cnt});
      add_edge(n + cnt++, 3 * n + 2, 1);
    }
    if (m.find(b) == m.end()) {
      m.insert({b, n + cnt});
      add_edge(n + cnt++, 3 * n + 2, 1);
    }
    add_edge(i + 1, m[a], 1);
    add_edge(i + 1, m[b], 1);
  }
  cout << max_flow(0, 3 * n + 2) << endl;
}