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

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int n, m, a;
  ll c;
  ll ans = 0;
  cin >> n >> m;
  vector<pair<ll, int> > v;
  for (int i = 0; i < m; i++) {
    cin >> a >> c;
    v.push_back({c, a});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < m; i++) {
    int g = gcd(n, v[i].second);
    if (n != g) {
      ans += v[i].first * (ll)(n / g - 1) * (ll)g;
      n = g;
    }
    if (n == 1) {
      cout << ans;
      return 0;
    }
  }
  cout << -1 << endl;
}