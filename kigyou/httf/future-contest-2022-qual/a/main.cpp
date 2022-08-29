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
vector<vector<int> > d(1000), childs(1000 + 1);
vector<int> in(1001), task(1001), sum(1001), sum2(1001);
set<int> mem;
set<pair<int, int> > t;
int dfs(int x) {
  if (sum2[x] != 0) {
    return sum2[x];
  }
  int res = 1;
  for (int i = 0; i < childs[x].size(); i++) {
    res += dfs(childs[x][i]);
  }
  sum2[x] = res;
  return res;
}

int dfs2(int x) {
  if (sum2[x] != 0) {
    return sum2[x];
  }
  int res = 0;
  for (int i = 0; i < childs[x].size(); i++) {
    res = max(res, dfs2(childs[x][i]));
  }
  res += sum[x];
  sum2[x] = res;
  return res;
}

int dfs3(int x) {
  if (sum2[x] != 0) {
    return sum2[x];
  }
  int res = 0;
  for (int i = 0; i < childs[x].size(); i++) {
    res += dfs3(childs[x][i]);
  }
  res += sum[x];
  sum2[x] = res;
  return res;
}

int main() {
  int n, m, k, r, u, v;
  cin >> n >> m >> k >> r;
  for (int i = 0; i < n; i++) {
    sum[i + 1] = 0;
    d[i].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> d[i][j];
      sum[i + 1] += d[i][j];
    }
  }
  for (int i = 0; i < r; i++) {
    cin >> u >> v;
    childs[u].push_back(v);
    in[v]++;
  }
  for (int i = 1; i <= m; i++) {
    mem.insert(i);
  }
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) {
      dfs(i);
      t.insert({0, i});
    }
  }
  for (int turn = 1; turn <= 2000; turn++) {
    // cout << "#turn " << turn << endl;
    // cout << "#member:";
    // for (auto&& xx : mem) {
    //   cout << xx << " ";
    // }
    // cout << endl;
    // cout << "#task:";
    // for (auto&& xx : t) {
    //   cout << xx << " ";
    // }
    // cout << endl;
    vector<pair<int, int> > p;
    while (!mem.empty() && !t.empty()) {
      task[(*mem.begin())] = (*t.begin()).second;
      p.push_back({*mem.begin(), (*t.begin()).second});
      mem.erase(mem.begin());
      t.erase(t.begin());
    }
    if (1) {
      if (!p.empty()) {
        cout << p.size() << " ";
      } else {
        cout << 0 << endl;
      }
      for (int i = 0; i < p.size(); i++) {
        cout << p[i].first << " " << p[i].second
             << (i != p.size() - 1 ? " " : "\n");
      }
    } else {
      cout << 0 << endl;
    }
    cout << flush;
    int x, y;
    cin >> x;
    if (x == -1) {
      return 0;
    }
    // cout << "#タスク完了:" << x << " ";
    for (int i = 0; i < x; i++) {
      cin >> y;
      // cout << y << " ";
      mem.insert(y);
      for (int j = 0; j < childs[task[y]].size(); j++) {
        int child = childs[task[y]][j];
        in[child]--;
        if (in[child] == 0) {
          t.insert({0, child});
        }
      }
    }
    // cout << endl;
  }
}
