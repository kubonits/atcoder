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

ll extgcd(ll a, ll b, ll& x, ll& y) {
  ll d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

int main() {
  ll n, t, s, k;
  cin >> t;
  while (t--) {
    cin >> n >> s >> k;
    int g = gcd(n, k);
    if (s % g) {
      cout << -1 << endl;
    } else {
      n /= g;
      k /= g;
      s /= g;
      ll x, y;
      extgcd(k, n, x, y);
      cout << (n - (s * x) % n) % n << endl;
    }
  }
}
