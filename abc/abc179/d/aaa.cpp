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
  vector<int> l(n), r(n), dp(n + 10), sum(n + 10);
  for (int i = 0; i <= n + 5; i++) {
    dp[i] = 0;
    sum[i] = 0;
  }
  sum[1] = 1;
  for (int i = 0; i < k; i++) {
    cin >> l[i] >> r[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << sum[i] << endl;
    for (int j = 0; j < k; j++) {
      for (int m = i + l[j]; m <= min(n, i + r[j]); m++) {
        sum[m] += sum[i];
        sum[m] %= MOD;
      }
    }
  }
}