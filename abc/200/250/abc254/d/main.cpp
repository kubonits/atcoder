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

int main() {
  ll n, cnt = 0;
  cin >> n;
  for (ll i = 1; i <= n; i++) {
    ll x = i, y = 1LL;
    for (ll j = 2; j <= sqrt(i); j++) {
      ll z = 0;
      while (x % j == 0) {
        x /= j;
        z ^= j;
      }
      if (z) {
        y *= z;
      }
    }
    y *= x;
    for (ll j = y; j <= n; j += y) {
      if ((ll)(i * j / sqrt(i * j)) == sqrt(i * j)) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
