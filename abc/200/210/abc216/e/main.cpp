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
  ll n, k;
  cin >> n >> k;
  ll ans = 0LL;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  ll left = 0LL, right = 2000000000LL, mid;
  while (left <= right) {
    mid = (left + right) / 2LL;
    ll cnt = 0LL;
    for (int i = 0; i < n; i++) {
      if (v[i] > mid) {
        cnt += v[i] - mid;
      }
    }
    if (cnt >= k) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (v[i] > left) {
      ans += (v[i] + 1) * v[i] / 2LL;
      ans -= (left + 1) * left / 2LL;
      k -= v[i] - left;
      v[i] = left;
    }
  }
  while (k > 0 && left > 0) {
    for (int i = 0; i < n; i++) {
      if (k > 0 && v[i] >= left) {
        ans += left;
        v[i]--;
        k--;
      }
    }
    left--;
  }
  cout << ans << endl;
}