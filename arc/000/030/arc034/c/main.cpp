#include <iostream>
#include <map>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main() {
  int a, b, c;
  map<int, ll> m;
  ll ans = 1LL;
  cin >> a >> b;
  for (int i = b + 1; i <= a; i++) {
    c = i;
    for (int j = 2; j * j <= i; j++) {
      while (c && c % j == 0) {
        m[j]++;
        c /= j;
      }
    }
    if (c != 1) {
      m[c]++;
    }
  }
  for (map<int, ll>::iterator it = m.begin(); it != m.end(); it++) {
    ans *= (it->second + 1LL);
    ans %= MOD;
  }
  cout << ans << endl;
}