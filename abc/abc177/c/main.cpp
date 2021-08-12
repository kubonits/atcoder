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
  int n;
  ll ans = 0;
  cin >> n;
  vector<ll> a(n), sum(n + 1);
  sum[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i + 1] = sum[i] + a[i];
    sum[i + 1] %= MOD;
  }
  for (int i = 0; i < n - 1; i++) {
    ans += a[i] * (MOD + sum[n] - sum[i + 1]);
    ans %= MOD;
  }
  cout << ans << endl;
}