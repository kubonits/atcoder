#include <algorithm>
#include <cmath>
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

int main() {
  int n, cnt[3] = {}, k, l, r;
  cin >> n >> k;
  vector<ll> a(n), p, m;
  ll ans = 1LL;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      cnt[1]++;
      p.push_back(a[i]);
    } else if (a[i] < 0) {
      m.push_back(a[i]);
      cnt[0]++;
    } else {
      cnt[2]++;
      p.push_back(a[i]);
    }
  }
  sort(a.begin(), a.end());
  sort(p.begin(), p.end());
  sort(m.begin(), m.end());
  if (k > cnt[0] + cnt[2]) {
    cout << 0 << endl;
    return 0;
  }
  if (n == k) {
    for (int i = 0; i < n; i++) {
      if (a[i] < 0) {
        ans *= (a[i] + MOD);
      } else {
        ans *= a[i];
      }
      ans %= MOD;
    }
    if (ans < 0) {
      ans += 10000LL * MOD;
      ans %= MOD;
    }
    cout << ans << endl;
    return 0;
  }
  if (k % 2 == 1 && cnt[0] == n) {
    for (int i = 0; i < k; i++) {
      ans *= (a[n - 1 - i] + MOD);
      ans %= MOD;
    }
    if (ans < 0) {
      ans += 10000LL * MOD;
      ans %= MOD;
    }
    cout << ans << endl;
    return 0;
  }
  if (k % 2 == 1 && cnt[2] == 0) {
    cout << 0 << endl;
    return 0;
  }
  l = 0;
  r = n - 1;
  for (int i = 0; i < k; i++) {
    if (i < k - 1 && a[l] * a[l + 1] > a[r] * a[r - 1]) {
      ans *= (a[l] + MOD);
      ans %= MOD;
      ans *= (a[l + 1] + MOD);
      ans %= MOD;
      l += 2;
      i++;
    } else {
      ans *= (a[r] + MOD) % MOD;
      ans %= MOD;
      r--;
    }
  }
  cout << (ans + MOD) % MOD << endl;
}