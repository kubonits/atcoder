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
  ll n, w, l, left = 0LL, ans = 0;
  cin >> n >> l >> w;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (left < a[i]) {
      ans += (a[i] - left + w - 1LL) / w;
    }
    left = a[i] + w;
  }
  if (left < l) {
    ans += (l - left + w - 1LL) / w;
  }
  cout << ans << endl;
}
