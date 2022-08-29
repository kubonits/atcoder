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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int n, m;

struct unionfind {
  int parent;
  int node;
  int edge;
};
unionfind g[100001], g2[100001];

void init() {
  for (int i = 0; i <= n; i++) {
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

void init2() {
  for (int i = 0; i <= n; i++) {
    g2[i].parent = i;
    g2[i].node = 1;
    g2[i].edge = 0;
  }
}

int ufind2(int x) {
  if (x == g2[x].parent) {
    return x;
  }
  int res = ufind2(g2[x].parent);
  g2[x].node = g2[res].node;
  g2[x].edge = g2[res].edge;
  g2[x].parent = res;
  return res;
}

void umerge2(int x, int y) {
  if (x > y) {
    x ^= y;
    y ^= x;
    x ^= y;
  }
  g2[x].node += g2[y].node;
  g2[x].edge += g2[y].edge + 1;
  g2[y].parent = x;
}

int main() {
  int a, b, l;
  n = 400;
  m = 1995;
  init();
  vector<int> x(n), y(n), f(m), f2(m);
  vector<pair<int, int> > e;
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      q;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    e.push_back({a, b});
  }
  // for (int i = 0; i < m; i++) {
  //   pair<int, int> p = q.top();
  //   q.pop();
  //   a = ufind(e[p.second].first);
  //   b = ufind(e[p.second].second);
  //   if (a != b) {
  //     umerge(a, b);
  //     f[p.second] = 1;
  //   } else {
  //     f[p.second] = 0;
  //   }
  // }
  for (int i = 0; i < m; i++) {
    cin >> l;
    a = ufind(e[i].first);
    b = ufind(e[i].second);
    if (a != b) {
      q.push({l * l, i});
      for (int j = i + 1; j < m; j++) {
        a = e[j].first;
        b = e[j].second;
        q.push({3 * ((x[a] - x[b]) * (x[a] - x[b]) +
                     (y[a] - y[b]) * (y[a] - y[b])),
                j});
      }
      init2();
      for (int k = 0; k < i; k++) {
        if (f[k] == 1) {
          umerge2(ufind(e[k].first), ufind(e[k].second));
        }
      }
      for (int j = i; j < m; j++) {
        pair<int, int> p = q.top();
        q.pop();
        a = ufind2(e[p.second].first);
        b = ufind2(e[p.second].second);
        if (a != b) {
          umerge2(a, b);
          f2[p.second] = 1;
        } else {
          f2[p.second] = 0;
        }
      }
      f[i] = f2[i];
    } else {
      f[i] = 0;
    }
    if (f[i] == 1) {
      umerge(ufind(e[i].first), ufind(e[i].second));
    }
    cout << f[i] << endl;
    cout << flush;
  }
}
