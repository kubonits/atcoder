#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main() {
  ll n, ans = 1LL, x, y, a, b, c;
  cin >> n;
  x = 1LL;
  b = 0LL;
  c = 0LL;
  y = 0LL;
  for (int i = 0; i < n; i++) {
    cin >> a;
    c /= 10LL;
    c += a;
    b += a * x;
    b %= MOD;
    x *= 10LL;
    x %= MOD;
    if (c < 10) {
      ans *= (b + 1LL);
      ans %= MOD;
      b = 0LL;
      x = 1LL;
      y = c = 0LL;
    }
  }
  ans *= (b + 1LL);
  ans %= MOD;
  cout << (ans + MOD - 1LL) % MOD << endl;
}