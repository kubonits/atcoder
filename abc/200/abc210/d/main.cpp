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
  int h, w;
  ll c, ans = 1000000000000000000;
  cin >> h >> w >> c;
  vector<vector<ll> > a(h, vector<ll>(w)), dp(h, vector<ll>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  dp[0][0] = a[0][0];
  for (int i = 1; i < h; i++) {
    ans = min(ans, a[i][0] + dp[i - 1][0] + c);
    dp[i][0] = min(a[i][0], dp[i - 1][0] + c);
  }
  for (int i = 1; i < w; i++) {
    ans = min(ans, a[0][i] + dp[0][i - 1] + c);
    dp[0][i] = min(a[0][i], dp[0][i - 1] + c);
  }
  for (int i = 1; i < h; i++) {
    for (int j = 1; j < w; j++) {
      ans = min(ans, a[i][j] + c + min(dp[i - 1][j], dp[i][j - 1]));
      dp[i][j] = min(a[i][j], c + min(dp[i - 1][j], dp[i][j - 1]));
    }
  }
  for (int i = 0; i < h; i++) {
    reverse(a[i].begin(), a[i].end());
  }
  dp[0][0] = a[0][0];
  for (int i = 1; i < h; i++) {
    ans = min(ans, a[i][0] + dp[i - 1][0] + c);
    dp[i][0] = min(a[i][0], dp[i - 1][0] + c);
  }
  for (int i = 1; i < w; i++) {
    ans = min(ans, a[0][i] + dp[0][i - 1] + c);
    dp[0][i] = min(a[0][i], dp[0][i - 1] + c);
  }
  for (int i = 1; i < h; i++) {
    for (int j = 1; j < w; j++) {
      ans = min(ans, a[i][j] + c + min(dp[i - 1][j], dp[i][j - 1]));
      dp[i][j] = min(a[i][j], c + min(dp[i - 1][j], dp[i][j - 1]));
    }
  }
  cout << ans << endl;
}