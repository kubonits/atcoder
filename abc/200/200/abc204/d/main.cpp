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
  int n, ans;
  cin >> n;
  vector<int> t(n), dp(n * 1000 + 1), sum(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  sort(t.begin(), t.end());
  sum[0] = t[0];
  for (int i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + t[i];
  }
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = min(sum[n - 1] / 2, sum[i]); j - t[i] >= 0; j--) {
      dp[j] |= dp[j - t[i]];
    }
  }
  ans = sum[n - 1];
  for (int i = 0; i <= sum[n - 1] / 2; i++) {
    if (dp[i]) {
      ans = min(ans, sum[n - 1] - i);
    }
  }
  cout << ans << endl;
}