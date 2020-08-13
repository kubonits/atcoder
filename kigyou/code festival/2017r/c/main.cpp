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
  ll n, k, l, r, mid;
  cin >> n >> k;
  vector<ll> w(n), d(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> d[i];
  }
  l = 0;
  r = 2000000000000000000;
  while (l <= r) {
    ll cnt = 0;
    mid = (l + r) / 2LL;
    for (int i = 0; i < n; i++) {
      if (mid >= w[i]) {
        cnt += (mid - w[i]) / d[i] + 1LL;
      }
    }
    if (cnt >= k) {
      r = mid - 1LL;
    } else {
      l = mid + 1LL;
    }
  }
  cout << l << endl;
}