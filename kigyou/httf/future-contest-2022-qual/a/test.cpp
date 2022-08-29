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
vector<pair<int, int> > a, b;
set<pair<int, int> > mem;
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
  vector<vector<int> > s(m, vector<int>(k)), ti(n + 1, vector<int>(m + 1));
  vector<int> num(m + 1), cnt(m + 1);
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
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> ti[i + 1][j + 1];
    }
  }
  for (int i = 1; i <= m; i++) {
    mem.insert({cnt[i], i});
  }
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) {
      dfs2(i);
      t.insert({-sum2[i], i});
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
    a.clear();
    b.clear();
    while (!mem.empty() && !t.empty()) {
      p.push_back({(*mem.begin()).second, (*t.begin()).second});
      a.push_back({mem.begin()->first, mem.begin()->second});
      b.push_back({-sum[t.begin()->first], t.begin()->second});
      mem.erase(mem.begin());
      t.erase(t.begin());
    }
    if (turn <= 2000) {
      //   cout << "# n=" << t.size() << " m=" << mem.size() << endl;
      if (!p.empty()) {
        cout << p.size() << " ";
      } else {
        cout << 0 << endl;
      }
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      for (int i = 0; i < p.size(); i++) {
        cout << a[i].second << " " << b[i].second
             << (i != p.size() - 1 ? " " : "\n");
        num[a[i].second] = ti[b[i].second][a[i].second];
        task[a[i].second] = b[i].second;
      }
    } else {
      cout << 0 << endl;
    }
    cout << flush;
    int x, y;
    // cout << "#タスク完了:" << x << " ";
    // cout << "# n=" << t.size() << " m=" << mem.size() << endl;
    for (int i = 1; i <= m; i++) {
      if (num[i]) {
        // cout << y << " ";
        num[i]--;
        if (num[i] == 0) {
          y = i;
          cnt[y]++;
          mem.insert({cnt[y], y});
          cout << "# タスク完了 メンバー" << y << " タスク" << task[y] << endl;
          for (int j = 0; j < childs[task[y]].size(); j++) {
            int child = childs[task[y]][j];
            in[child]--;
            if (in[child] == 0) {
              t.insert({-sum2[child], child});
            }
          }
        }
      }
    }
    // cout << "# n=" << t.size() << " m=" << mem.size() << endl;
    // cout << endl;
  }
  //   for (int i = 1; i <= n; i++) {
  //     cout << "#" << in[i] << endl;
  //   }
}
