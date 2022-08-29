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
  ll n, a, b, p, q, r, s;
  cin >> n >> a >> b >> p >> q >> r >> s;
  vector<string> ans(q - p + 1LL);
  string t(s - r + 1LL, '.');
  for (ll i = 0LL; i < q - p + 1LL; i++) {
    ans[(int)i] = t;
  }
  for (ll i = p; i <= q; i++) {
    for (ll j = r; j <= s; j++) {
      if (j - i == b - a || j + i == a + b) {
        ans[i - p][j - r] = '#';
      }
    }
    cout << ans[i - p] << endl;
  }
}
