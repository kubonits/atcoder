#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1LL;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n /= 2LL;
  }
  return res;
}

ll gcd(ll x, ll y) {
  if (y == 0) {
    return x;
  }
  return gcd(y, x % y);
}

int main() {
  int n, flag = 1;
  ll a[10000], ans = 0LL, x = 1LL, b[10000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    b[i] = a[i];
  }
  for (ll i = 2; i <= 1000; i++) {
    flag = 1;
    while (flag == 1) {
      flag = 0;
      for (int j = 0; j < n; j++) {
        if (a[j] % i == 0) {
          flag = 1;
          a[j] /= i;
        }
      }
      if (flag) {
        x *= i;
        x %= MOD;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] != 1) {
      x *= a[i];
      x %= MOD;
      for (int j = i + 1; j < n; j++) {
        if (a[i] == a[j]) {
          a[j] /= a[i];
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    ll y = x * mod_pow(b[i], MOD - 2LL, MOD);
    y %= MOD;
    ans += y;
    ans %= MOD;
  }
  printf("%lld\n", ans);
}