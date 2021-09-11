#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
  ll n, m, a, b, ans = 0, k;
  cin >> n >> m >> k;
  vector<ll> suma(n + 10), sumb(m + 10);
  for (int i = 0; i < n; i++) {
    cin >> a;
    suma[i + 1] = suma[i] + a;
  }
  for (int i = 0; i < m; i++) {
    cin >> b;
    sumb[i + 1] = sumb[i] + b;
  }
  for (int i = 0; i <= n; i++) {
    while (m >= 0 && suma[i] + sumb[m] > k) {
      m--;
    }
    if (m >= 0) {
      ans = max(ans, i + m);
    }
  }
  cout << ans << endl;
}