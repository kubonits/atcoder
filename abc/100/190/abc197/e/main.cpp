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
  ll n, x, c, mini, maxi, flag = 0;
  cin >> n;
  vector<vector<ll> > v(n + 1), dp(n + 1LL, vector<ll>(2));
  for (int i = 0; i < n; i++) {
    cin >> x >> c;
    v[c].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (v[i].empty()) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1];
    } else {
      sort(v[i].begin(), v[i].end());
      if (flag == 0) {
        dp[i][0] = abs(v[i].back()) + v[i].back() - v[i][0];
        dp[i][1] = abs(v[i][0]) + v[i].back() - v[i][0];
        flag = 1;
      } else {
        dp[i][1] = min(dp[i - 1][0] + abs(mini - v[i][0]),
                       dp[i - 1][1] + abs(maxi - v[i][0])) +
                   v[i].back() - v[i][0];
        dp[i][0] = min(dp[i - 1][0] + abs(mini - v[i].back()),
                       dp[i - 1][1] + abs(maxi - v[i].back())) +
                   v[i].back() - v[i][0];
      }
      mini = v[i][0];
      maxi = v[i].back();
    }
  }
  cout << min(dp[n][0] + abs(mini), dp[n][1] + abs(maxi)) << endl;
}
