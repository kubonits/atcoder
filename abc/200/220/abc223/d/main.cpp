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

int main() {
  int n, m, a, b;
  cin >> n >> m;
  vector<int> pre(n + 1), ans;
  vector<vector<int> > child(n + 1);
  set<int> s;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    child[a].push_back(b);
    pre[b]++;
  }
  for (int i = 1; i <= n; i++) {
    if (pre[i] == 0) {
      s.insert(i);
    }
  }
  while (!s.empty()) {
    int x = *s.begin();
    s.erase(x);
    ans.push_back(x);
    // cout << x << endl;
    for (int i = 0; i < child[x].size(); i++) {
      pre[child[x][i]]--;
      if (pre[child[x][i]] == 0) {
        s.insert(child[x][i]);
      }
    }
  }
  if (ans.size() == n) {
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}
