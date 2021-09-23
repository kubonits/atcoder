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
  ll n, k, left = 0LL, right = 2000000000000000000, mid, ans = 1LL;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  while (left <= right) {
    mid = (left + right) / 2LL;
    ll x = k;
    int flag = 1;
    for (int i = 0; i < n; i++) {
      x -= max(mid - a[i], 0LL);
      if (x < 0) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      left = mid + 1LL;
    } else {
      right = mid - 1LL;
    }
  }
  if (right >= a.back()) {
    cout << right << endl;
    return 0;
  }
  vector<ll> sum(300001), cnt(300001);
  for (int i = 0; i <= 300000; i++) {
    sum[i] = cnt[i] = 0LL;
  }
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
    sum[a[i]] += a[i];
  }
  for (int i = 1; i <= 300000; i++) {
    sum[i] += sum[i - 1];
    cnt[i] += cnt[i - 1];
  }
  for (ll i = 2LL; i <= 300000LL; i++) {
    ll x = k;
    for (ll j = i; j <= 300000LL; j += i) {
      x -= (cnt[j] - cnt[j - i]) * j - (sum[j] - sum[j - i]);
    }
    if (300000LL % i) {
      x -= (cnt[300000] - cnt[300000LL / i * i]) * (300000LL / i * i + i) -
           (sum[300000] - sum[300000LL / i * i]);
    }
    if (x >= 0) {
      ans = i;
    }
  }
  cout << ans << endl;
}
