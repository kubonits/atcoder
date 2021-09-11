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

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  ll l, r, ans = 0;
  cin >> l >> r;
  vector<int> v(r + 1);
  for (int i = 2; i <= r; i++) {
    v[i] = 0;
  }
  for (int i = 2; i <= r; i++) {
    if (v[i] == 0) {
      for (int j = 2 * i; j <= r; j += i) {
        v[j]++;
      }
      ll x = r / i - (l - 1) / i;
      if (x && i >= l) {
        x--;
      }
      ans += x * x - x;
    } else if (v[i] == 1) {
      if (i >= l) {
        ll x = r / i - (l - 1) / i - 1;
        ans -= 2LL * x;
      }
    } else {
      ll x = r / i - (l - 1) / i;
      if (x && i >= l) {
        ans -= 2LL * v[i] * (x - 1);
        x--;
        cout << i << " " << ans << endl;
      }
      if (v[i] % 2) {
        ans += x * x - x;
      } else {
        ans -= x * x - x;
      }
    }
    cout << i << " " << ans << endl;
  }
  cout << ans << endl;
  ll ans2 = 0;
  for (int i = l; i <= r; i++) {
    for (int j = i + 1; j <= r; j++) {
      if (gcd(i, j) != 1 && i != gcd(i, j) && j != gcd(i, j)) {
        ans2 += 2;
      }
    }
  }
  cout << ans2 << endl;
}