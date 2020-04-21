#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n /= 2LL;
  }
  return res;
}

int main() {
  ll n, k, ans = 0LL, cnt[100001] = {};
  vector<int> v[100001];
  int a[1001] = {};
  scanf("%lld%lld", &n, &k);
  for (int i = 1; i <= k; i++) {
    for (int j = 2 * i; j <= k; j += i) {
      v[j].push_back(i);
    }
  }
  for (ll i = k; i >= 1LL; i--) {
    ll num = mod_pow(k / i, n, MOD);
    num += MOD - cnt[i];
    num %= MOD;
    for (int j = 0; j < v[i].size(); j++) {
      cnt[v[i][j]] += num;
      cnt[v[i][j]] %= MOD;
    }
    num *= i;
    num %= MOD;
    ans += num;
    ans %= MOD;
  }
  printf("%lld\n", ans);
}