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
#define INF 100000
using namespace std;
typedef long long ll;
#include <cstring>

struct edge {
  int to, cap, rev;
};

vector<edge> g[10010];
bool used[10010];

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
  int n, m;
  string s[100];
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '.' && (i + j) % 2) {
        add_edge(0, i * m + j + 1, 1);
      } else if (s[i][j] == '.') {
        add_edge(i * m + j + 1, 10001, 1);
      }
      if (i != n - 1 && s[i][j] == '.' && s[i + 1][j] == '.') {
        if ((i + j) % 2) {
          add_edge(i * m + j + 1, (i + 1) * m + j + 1, 1);
        } else {
          add_edge((i + 1) * m + j + 1, (i)*m + j + 1, 1);
        }
      }
      if (j != m - 1 && s[i][j] == '.' && s[i][j + 1] == '.') {
        if ((i + j) % 2) {
          add_edge(i * m + j + 1, (i)*m + j + 1 + 1, 1);
        } else {
          add_edge((i)*m + j + 1 + 1, (i)*m + j + 1, 1);
        }
      }
    }
  }
  int ans = max_flow(0, 10001);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2) {
        int x = i * m + j + 1;
        for (int k = 0; k < g[x].size(); k++) {
          if (g[x][k].to != 0 && g[x][k].cap == 0) {
            int y = x - g[x][k].to;
            if (m != 1 && y == 1) {
              s[i][j] = '<';
              s[i][j - 1] = '>';
            } else if (m != 1 & y == -1) {
              s[i][j] = '>';
              s[i][j + 1] = '<';
            } else if (y == -m) {
              s[i][j] = 'v';
              s[i + 1][j] = '^';
            } else if (y == m) {
              s[i][j] = '^';
              s[i - 1][j] = 'v';
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    cout << s[i] << endl;
  }
}