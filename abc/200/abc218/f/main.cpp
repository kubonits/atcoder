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

int g[400][400], d[400];
int n, m;
void bfs() {
  int x = 0;
  queue<int> q;
  q.push(0);
  d[0] = 0;
  while (!q.empty()) {
    x = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if (g[x][i] == 1 && d[x] + 1 < d[i]) {
        d[i] = d[x] + 1;
        q.push(i);
      }
    }
  }
}

int main() {
  cin >> n >> m;
  vector<int> a(m), b(m);
  vector<pair<int, int> > v;
  set<pair<int, int> > s;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    g[a[i]][b[i]] = 1;
    v.push_back({a[i], b[i]});
  }
  for (int i = 0; i < 400; i++) {
    d[i] = 10000;
  }
  bfs();
  if (d[n - 1] == 10000) {
    for (int i = 0; i < m; i++) {
      cout << -1 << endl;
    }
    return 0;
  }
  int ans = d[n - 1];
  int x = n - 1;
  while (x) {
    for (int i = 0; i < n; i++) {
      if (g[i][x] && d[i] + 1 == d[x]) {
        s.insert({i, x});
        x = i;
        break;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (s.find({a[i], b[i]}) == s.end()) {
      cout << ans << endl;
    } else {
      for (int j = 0; j < n; j++) {
        d[j] = 10000;
      }
      g[a[i]][b[i]] = 0;
      bfs();
      g[a[i]][b[i]] = 1;
      cout << (d[n - 1] == 10000 ? -1 : d[n - 1]) << endl;
    }
  }
}
