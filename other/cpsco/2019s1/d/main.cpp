#include <iostream>
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
    n = n >> 1;
  }
  return res;
}
int main() {
  ll n;
  cin >> n;
  cout << 8 * mod_pow(5, n - 1LL, MOD) % MOD << endl;
}