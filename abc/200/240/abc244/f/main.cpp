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

int main() {
  int n, m, x, y;
  ll ans = 0LL;
  cin >> n >> m;
  vector<ll> mini((1 << n));
  vector<vector<ll> > v(n + 1), dp((1 << n), vector<ll>(n + 1)),
      visited((1 << n), vector<ll>(n + 1));
  queue<pair<int, int> > q;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 0; i < (1 << n); i++) {
    mini[i] = 1000000000;
    for (int j = 0; j <= n; j++) {
      dp[i][j] = 1000000000;
    }
  }
  dp[0][0] = 0;
  mini[0] = 0;
  for (int i = 0; i < n; i++) {
    dp[1 << i][i + 1] = 1;
    q.push({(1 << i), i + 1});
  }
  while (!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    if (visited[x][y] == 0) {
      visited[x][y] = 1;
      mini[x] = min(mini[x], dp[x][y]);
      for (int i = 0; i < v[y].size(); i++) {
        if (dp[x ^ (1 << (v[y][i] - 1))][v[y][i]] > dp[x][y] + 1) {
          dp[x ^ (1 << (v[y][i] - 1))][v[y][i]] = dp[x][y] + 1;
          q.push({x ^ (1 << (v[y][i] - 1)), v[y][i]});
        }
      }
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    ans += mini[i];
  }
  cout << ans << endl;
}
