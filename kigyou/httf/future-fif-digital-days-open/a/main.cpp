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

vector<pair<int, int> > ansp;
int n, k, b;

struct unionfind {
  int parent;
  int node;
  int edge;
};
unionfind g[100001];

void init() {
  for (int i = 0; i <= b; i++) {
    g[i].parent = i;
    g[i].node = 1;
    g[i].edge = 0;
  }
}

int ufind(int x) {
  if (x == g[x].parent) {
    return x;
  }
  int res = ufind(g[x].parent);
  g[x].node = g[res].node;
  g[x].edge = g[res].edge;
  g[x].parent = res;
  return res;
}

void umerge(int x, int y) {
  if (x > y) {
    x ^= y;
    y ^= x;
    x ^= y;
  }
  g[x].node += g[y].node;
  g[x].edge += g[y].edge + 1;
  g[y].parent = x;
}

void merge(int sx, int sy, int tx, int ty, vector<string>& ans) {
  int x = sx, y = sy;
  // cout << sx << " " << sy << " " << tx << " " << ty << endl;
  while (x != tx || y != ty) {
    if (ans[x][y] == '.') {
      ans[x][y] = '#';
      ansp.push_back({x, y});
    }
    if (x > tx) {
      x--;
    } else if (x < tx) {
      x++;
    } else if (y > ty) {
      y--;
    } else if (y < ty) {
      y++;
    }
  }
  if (ans[x][y] == '.') {
    ans[x][y] = '#';
    ansp.push_back({x, y});
  }
}

int main() {
  cin >> n >> k >> b;
  vector<int> h(b), w(b), c(b);
  vector<pair<int, int> > p(k);
  vector<string> ans(n);
  vector<vector<string> > s(b);
  for (int i = 0; i < n; i++) {
    string t(50, '.');
    ans[i] = t;
  }
  vector<pair<int, pair<int, int> > > dis;
  for (int i = 0; i < k; i++) {
    cin >> p[i].first >> p[i].second;
  }
  for (int i = 0; i < b; i++) {
    cin >> h[i] >> w[i] >> c[i];
    s[i].resize(h[i]);
    for (int j = 0; j < h[i]; j++) {
      cin >> s[i][j];
    }
  }
  // cout << "C";
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
      dis.push_back(
          {abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second),
           {i, j}});
    }
  }
  sort(dis.begin(), dis.end());
  // cout << "B";
  merge(p[dis[0].second.first].first, p[dis[0].second.first].second,
        p[dis[0].second.second].first, p[dis[0].second.second].second, ans);
  // cout << "A";
  for (int i = 0; i < k; i++) {
    int mini = 2501, sx = -1, sy = -1, tx = -1, ty = -1;
    for (int kk = 0; kk < k; kk++) {
      for (int j = 0; j < n; j++) {
        for (int l = 0; l < n; l++) {
          if (ans[p[kk].first][p[kk].second] == '.' && ans[j][l] == '#') {
            if (mini > abs(p[kk].first - j) + abs(p[kk].second - l)) {
              // cout << i << endl;
              mini = abs(p[kk].first - j) + abs(p[kk].second - l);
              tx = j;
              ty = l;
              sx = p[kk].first;
              sy = p[kk].second;
            }
          }
        }
      }
    }
    if (sx >= 0 && sy >= 0) {
      merge(sx, sy, tx, ty, ans);
    }
  }
  cout << ansp.size() << endl;
  for (int i = 0; i < ansp.size(); i++) {
    cout << 1 << " " << ansp[i].first << " " << ansp[i].second << endl;
  }
}
