#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007

typedef long long ll;

ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n = n >> 1;
  }
  return res;
}

int main() {
  ll a, b, n;
  vector<ll> v;
  cin >> n >> a >> b;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  if (a == 1LL) {
    for (int i = 0; i < n; i++) {
      cout << v[i] << endl;
    }
    return 0;
  }
  while (b && v[0] * a < v[n - 1]) {
    v[0] *= a;
    sort(v.begin(), v.end());
    b--;
  }
  for (int i = 0; i < n; i++) {
    v[i] %= MOD;
  }
  while (b % n) {
    v[0] *= a;
    v[0] %= MOD;
    ll temp = v[0];
    for (int i = 0; i < n - 1; i++) {
      v[i] = v[i + 1];
    }
    v[n - 1] = temp;
    b--;
  }
  for (int i = 0; i < n; i++) {
    cout << v[i] * mod_pow(a, b / n, MOD) % MOD << endl;
  }
}