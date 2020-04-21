#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll ans = 0LL, suml[200011], sumr[200011], k;
int main() {
  ll n;
  cin >> n >> k;
  suml[1] = 0LL;
  sumr[1] = n;
  for (ll i = 1; i <= n; i++) {
    suml[i + 1LL] = suml[i] + i;
    suml[i + 1LL] %= MOD;
  }
  for (ll i = 1; i <= n; i++) {
    sumr[i + 1LL] = sumr[i] + (n - i);
    sumr[i + 1LL] %= MOD;
  }
  for (ll i = k; i <= n + 1; i++) {
    ans += MOD - suml[i] + sumr[i] + 1LL;
    ans %= MOD;
  }
  cout << ans << endl;
}