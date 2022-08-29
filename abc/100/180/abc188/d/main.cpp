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
  ll n, c, x, y, z, ans = 0LL;
  map<ll, ll> m;
  cin >> n >> c;
  m.insert({1000000001LL, 0});
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    if (m.find(x) == m.end()) {
      m.insert({x, z});
    } else {
      m[x] += z;
    }
    if (m.find(y + 1LL) == m.end()) {
      m.insert({y + 1LL, -z});
    } else {
      m[y + 1LL] -= z;
    }
  }
  ll a = 0LL, b = 0LL;
  for (auto &&x : m) {
    ans += min(b, c) * (x.first - a);
    a = x.first;
    b += x.second;
  }
  cout << ans << endl;
}
