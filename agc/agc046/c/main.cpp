#include <algorithm>
#include <cmath>
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

int main() {
  ll n, a = 0, b = 0, k;
  string s;
  cin >> s >> k;
  n = s.length();
  k = min(300LL, k);
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      a++;
    } else {
      b++;
    }
  }
  vector<vector<vector<ll> > > dp(a + 10);
  for (int i = 0; i <= a; i++) {
    dp[i].resize(b + 10);
    for (int j = 0; j <= b; j++) {
      dp[i][j].resize(k + 1LL);
    }
  }
  a = b = 0;
  dp[0][0][0] = 1LL;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      a++;
    } else {
      b++;
    }
    dp[a][b][0] = 1LL;
  }
  for (ll i = 1; i <= k; i++) {
    dp[0][0][i] = 1LL;
    for (ll j = 1; j <= n; j++) {
      for (ll l = 0; l <= a && l <= j; l++) {
        ll x;
        if (j - l - 1LL >= 0LL && j - l <= b && dp[l][j - l - 1LL][i - 1LL]) {
          dp[l][j - l][i] =
              dp[l][j - l - 1LL][i - 1LL] * (l + 1LL) + dp[l][j - l][i - 1LL];
          dp[l][j - l][i] %= MOD;
        } else if (j - l >= 0LL && j - l <= b) {
          dp[l][j - l][i] = dp[l][j - l][i - 1LL];
        }
      }
    }
  }
  cout << dp[a][b][k] << endl;
  for (int l = 0; l <= k; l++) {
    for (int i = 0; i <= a; i++) {
      for (int j = 0; j <= b; j++) {
        cout << dp[i][j][l] << "\t";
      }
      cout << endl;
    }
    cout << endl;
  }
}