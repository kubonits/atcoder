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

vector<int> d;
struct unionfind {
  int parent;
  int node;
  int edge;
};
unionfind g[200001];

void init() {
  for (int i = 0; i <= n; i++) {
    g[i].parent = i;
    g[i].node = 1;
    g[i].edge = d[i];
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
  g[x].edge += g[y].edge - 2;
  g[y].parent = x;
}

int main() {
  int a, b;
  priority_queue<pair<int, int> > q, q1;
  vector<pair<int, int> > ans;
  cin >> n >> m;
  d.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  init();
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    if (d[a] < 1 || d[b] < 1) {
      cout << -1 << endl;
      return 0;
    }
    d[a]--;
    d[b]--;
    a = ufind(a);
    b = ufind(b);
    if (a != b) {
      umerge(a, b);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (ufind(i) == i) {
      q.push({g[i].edge, i});
    }
  }
  q1.push({d[q.top().second], q.top().second});
  while (!q.empty()) {
    q.pop();
  }
  int num = q1.top().second;
  // cout << num << endl;
  for (int i = 1; i <= n; i++) {
    if (ufind(i) != i && ufind(i) == num) {
      cout << i << endl;
      q1.push({d[i], i});
    } else if (ufind(i) != num) {
      q.push({d[i], i});
    }
  }
  while (!q.empty()) {
    int x, y;
    x = q1.top().second;
    y = q.top().second;
    cout << x << " " << y << endl;
    if (ufind(x) == ufind(y)) {
      cout << "not" << endl;
      q1.push(q.top());
      q.pop();
    } else {
      if (d[x] < 1 || d[y] < 1) {
        cout << -1 << endl;
        return 0;
      }
      d[x]--;
      d[y]--;
      q1.pop();
      q.pop();
      q1.push({d[x], x});
      q1.push({d[y], y});
      ans.push_back({x, y});
      umerge(ufind(x), ufind(y));
    }
  }
  for (int i = 1; i <= n; i++) {
    if (d[i] != 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}
