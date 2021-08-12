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
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int t;
  ll n, m, a, b;
  cin >> t;
  while (t--) {
    ll ans = 0LL;
    cin >> n >> m >> a >> b;
    for (ll i = 0; i < n; i++) {
      ans += (a * i + b) / m;
    }
    cout << ans << endl;
  }
}