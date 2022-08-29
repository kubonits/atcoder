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
#define MOD2 998244353
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
  int n;
  ll maxi, ans = 0;
  cin >> n;
  vector<ll> a(n), b(n), v;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  maxi = a[0] * b[0] / gcd(a[0], b[0]);
  for (int i = 0; i < n; i++) {
    maxi = gcd(maxi, a[i] * b[i] / gcd(a[i], b[i]));
  }
  for (int i = 1; i <= sqrt(maxi); i++) {
    if (maxi % i == 0) {
      v.push_back(i);
      v.push_back(maxi / i);
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    for (int j = i; j < v.size(); j++) {
      int flag = 1;
      for (int k = 0; k < n; k++) {
        if ((a[k] % v[i] || b[k] % v[j]) && (b[k] % v[i] || a[k] % v[j])) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        ans = max(ans, v[i] * v[j] / gcd(v[i], v[j]));
      }
    }
  }
  cout << ans << endl;
}
