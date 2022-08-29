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
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<vector<pair<ll, ll> > > dp(n + 1, vector<pair<ll, ll> >(2));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[1][0] = {a[0], 1LL};
  for (int i = 1; i < n; i++) {
    dp[i + 1][0] = {(dp[i][0].first + dp[i][1].first +
                     a[i] * (dp[i][0].second + dp[i][1].second)) %
                        MOD,
                    (dp[i][0].second + dp[i][1].second) % MOD};
    dp[i + 1][1] = {(dp[i][0].first + (MOD - a[i]) * dp[i][0].second) % MOD,
                    dp[i][0].second};
  }
  cout << (dp[n][0].first + dp[n][1].first) % MOD << endl;
}
