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
  while (1) {
    priority_queue<pair<int, int> > q, q1;
    vector<pair<int, int> > ans;
    // cin >> n >> m;
    n = 10;
    m = 3;
    vector<vector<int> > t(n + 1);
    vector<pair<int, int> > e;
    for (int i = 0; i < n - 1; i++) {
      int x = rand() % (i + 1) + 1;
      t[x].push_back(i + 2);
      t[i + 2].push_back(x);
      e.push_back({x, i + 2});
    }
    d.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      //   cin >> d[i];
      d[i] = t[i].size();
    }
    init();
    for (int i = 0; i < m; i++) {
      //   cin >> a >> b;
      a = e[i].first;
      b = e[i].second;
      if (d[a] < 1 || d[b] < 1) {
        for (int z = 0; z < n; z++) {
          cout << t[z + 1].size() << " ";
        }
        cout << endl;
        for (int z = 0; z < m; z++) {
          cout << e[z].first << " " << e[z].second << endl;
        }
        cout << "A" << endl;
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
        // cout << i << endl;
        q1.push({d[i], i});
      } else if (ufind(i) != num) {
        q.push({d[i], i});
      }
    }
    while (!q.empty()) {
      int x, y;
      x = q1.top().second;
      y = q.top().second;
      if (ufind(x) == ufind(y)) {
        q1.push(q.top());
        q.pop();
      } else {
        if (d[x] < 1 || d[y] < 1) {
          for (int z = 0; z < n; z++) {
            cout << t[z + 1].size() << " ";
          }
          cout << endl;
          for (int z = 0; z < m; z++) {
            cout << e[z].first << " " << e[z].second << endl;
          }
          cout << "B" << endl;
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
        for (int z = 0; z < n; z++) {
          cout << t[z + 1].size() << " ";
        }
        cout << endl;
        for (int z = 0; z < m; z++) {
          cout << e[z].first << " " << e[z].second << endl;
        }
        cout << "C" << endl;
        cout << -1 << endl;
        return 0;
      }
    }
    // for (int i = 0; i < ans.size(); i++) {
    //   cout << ans[i].first << " " << ans[i].second << endl;
    // }
  }
}
