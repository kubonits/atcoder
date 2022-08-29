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
  int n, a;
  ll ans = 0LL;
  cin >> n;
  map<ll, ll> m;
  for (int i = 0; i < n; i++) {
    cin >> a;
    m[a]++;
  }
  ans += m[1] * m[1] * m[1];
  for (int i = 2; i <= 200000; i++) {
    ans += 2LL * m[1] * m[i] * m[i];
  }
  for (int i = 2; i <= 200000; i++) {
    for (int j = 2; j <= sqrt(i); j++) {
      if (i % j == 0 && j * j != i) {
        ans += 2LL * m[i] * m[j] * m[i / j];
      } else if (i % j == 0) {
        ans += m[i] * m[j] * m[j];
      }
    }
  }
  cout << ans << endl;
}