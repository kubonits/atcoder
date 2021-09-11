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

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> l(n), r(n), dp(n + 10), sum(n + 10);
  for (int i = 0; i <= n + 5; i++) {
    dp[i] = 0;
    sum[i] = 0;
  }
  sum[1] = 0;
  for (int i = 0; i < k; i++) {
    cin >> l[i] >> r[i];
  }
  for (int i = 0; i < k; i++) {
    sum[l[i] + 1] += 1;
    sum[r[i] + 2] += MOD - 1;
  }
  for (int i = 2; i <= n; i++) {
    sum[i] += sum[i - 1];
    sum[i] %= MOD;
    if (sum[i] < 0) {
      sum[i] += MOD;
    }
    for (int j = 0; j < k; j++) {
      if (i + l[j] <= n) {
        sum[i + l[j]] += sum[i];
        sum[i + l[j]] % MOD;
      }
      if (i + r[j] + 1 <= n) {
        sum[i + r[j] + 1] += MOD - sum[i];
        sum[i + r[j] + 1] % MOD;
      }
    }
  }
  cout << sum[n] << endl;
}