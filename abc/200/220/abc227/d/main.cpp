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
  ll n, k, left, right, mid;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  left = 0;
  right = 1000000000000000000 / k;
  while (left <= right) {
    mid = (left + right) / 2;
    ll cnt = 0LL;
    for (int i = 0; i < n; i++) {
      cnt += min(mid, a[i]);
    }
    if (cnt >= mid * k) {
      left = mid + 1LL;
    } else {
      right = mid - 1LL;
    }
  }
  cout << right << endl;
}
