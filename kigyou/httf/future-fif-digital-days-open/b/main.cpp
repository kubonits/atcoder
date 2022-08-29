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

vector<pair<int, pair<int, int> > > ansp;
int n, k, b;

struct unionfind {
  int parent;
  int node;
  int edge;
};
unionfind g[100001];

void init() {
  for (int i = 0; i <= 2500; i++) {
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
      ansp.push_back({1, {x, y}});
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
    ansp.push_back({1, {x, y}});
  }
}

double calc(set<pair<int, int> >& sp, vector<string>& s, int x, int y) {
  int res = 0;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s[i].length(); j++) {
      if (s[i][j] == '#' && sp.find({x + i, y + j}) != sp.end()) {
        res++;
      }
    }
  }
  return (double)res;
}

int check(vector<string>& ans, vector<string>& s, int x, int y, int h, int w) {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#' && ans[x + i][y + j] == '#') {
        return 0;
      }
    }
  }
  return 1;
}

void draw(vector<string>& ans, vector<string>& s, int x, int y) {
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s[i].length(); j++) {
      if (s[i][j] == '#') {
        ans[i + x][y + j] = '#';
      }
    }
  }
}

int main() {
  cin >> n >> k >> b;
  vector<int> h(b), w(b);
  vector<double> c(b);
  vector<pair<int, int> > p(k);
  vector<string> ans(n);
  vector<vector<string> > s(b);
  vector<pair<pair<double, int>, pair<int, int> > > va;
  set<pair<int, int> > sp;
  vector<pair<int, pair<int, int> > > dis;
  for (int i = 0; i < n; i++) {
    string t(50, '.');
    ans[i] = t;
  }
  for (int i = 0; i < k; i++) {
    cin >> p[i].first >> p[i].second;
    sp.insert({p[i].first, p[i].second});
  }
  for (int i = 0; i < b; i++) {
    cin >> h[i] >> w[i] >> c[i];
    s[i].resize(h[i]);
    for (int j = 0; j < h[i]; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < b; i++) {
    for (int xx = 0; xx <= n - h[i]; xx++) {
      for (int yy = 0; yy <= n - w[i]; yy++) {
        double score = calc(sp, s[i], xx, yy) / c[i];
        if (score) {
          va.push_back({{score, i}, {xx, yy}});
        }
      }
    }
  }
  sort(va.begin(), va.end());
  reverse(va.begin(), va.end());
  for (int i = 0; i < va.size(); i++) {
    int x = va[i].second.first, y = va[i].second.second,
        index = va[i].first.second;
    if (check(ans, s[index], x, y, h[index], w[index])) {
      ansp.push_back({index + 1, {x, y}});
      draw(ans, s[index], x, y);
    }
  }
  init();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (ans[i][j] == '#' && ans[i + 1][j] == '#') {
        int x = ufind(i * n + j), y = ufind((i + 1) * n + j);
        if (x != y) {
          umerge(x, y);
        }
      }
      if (ans[i][j] == '#' && ans[i][j + 1] == '#') {
        int x = ufind(i * n + j), y = ufind((i)*n + j + 1);
        if (x != y) {
          umerge(x, y);
        }
      }
    }
  }
  for (int kk = 0; kk < k; kk++) {
    int mini = 2500, minii = -1, minij = -1;
    for (int i = 0; i < n * n; i++) {
      for (int j = i + 1; j < n * n; j++) {
        if (ans[i / n][i % n] == '#' && ans[j / n][j % n] == '#' &&
            ufind(i) != ufind(j)) {
          // cout << i << " " << j << endl;
          if (mini > (abs(i / n - j / n) + abs(i % n - j % n)) &&
              (abs(i / n - j / n) + abs(i % n - j % n))) {
            mini = abs(i / n - j / n) + abs(i % n - j % n);
            minii = i;
            minij = j;
          }
        }
      }
    }
    // cout << minii << " " << minij << endl;
    if (minii >= 0) {
      merge(minii / n, minii % n, minij / n, minij % n, ans);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i + 1 < n && ans[i][j] == '#' && ans[i + 1][j] == '#') {
          int x = ufind(i * n + j), y = ufind((i + 1) * n + j);
          if (x != y) {
            umerge(x, y);
          }
        }
        if (j + 1 < n && ans[i][j] == '#' && ans[i][j + 1] == '#') {
          int x = ufind(i * n + j), y = ufind((i)*n + j + 1);
          if (x != y) {
            umerge(x, y);
          }
        }
      }
    }
    // for (int i = 0; i < n; i++) {
    //   cout << ans[i] << endl;
    // }
    // cout << endl;
  }
  cout << ansp.size() << endl;
  for (int i = 0; i < ansp.size(); i++) {
    cout << ansp[i].first << " " << ansp[i].second.first << " "
         << ansp[i].second.second << endl;
  }
}
