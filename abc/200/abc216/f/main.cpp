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
#define MOD 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int dp[5001][5001][2];

int main() {
  int n, num = 0;
  int ans = 0;
  cin >> n;
  vector<int> a(n), b(n);
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    num = max(num, a[i]);
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    v.push_back({a[i], b[i]});
  }
  sort(v.begin(), v.end());
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= num; j++) {
      dp[i + 1][j][0] += dp[i][j][0];
      dp[i + 1][j][0] %= MOD;
      if (j + v[i].second <= num) {
        dp[i + 1][j + v[i].second][1] += dp[i][j][0];
        dp[i + 1][j + v[i].second][1] %= MOD;
        dp[i + 1][j + v[i].second][0] += dp[i][j][0];
        dp[i + 1][j + v[i].second][0] %= MOD;
        if (j + v[i].second <= v[i].first) {
          ans += dp[i + 1][j + v[i].second][1];
          ans %= MOD;
        }
      }
    }
  }
  cout << ans << endl;
}