#include <cmath>
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  ll n, ans;
  cin >> n;
  ans = n - 2LL;
  if (n == 2) {
    cout << 0 << endl;
    return 0;
  }
  ll r = sqrt(n);
  if (r * r != n) {
    cout << -1 << endl;
    return 0;
  }
  for (ll i = sqrt(n); i >= 3; i--) {
    ans += (i - 1LL) * (i - 1LL) - i + 1LL;
  }
  cout << ans + 1LL << endl;
}