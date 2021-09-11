#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
int n, a[200000];
int main() {
  map<int, ll> m;
  ll ans = 0LL;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (m.find(i - a[i]) != m.end()) {
      ans += m[i - a[i]];
    }
    if (m.find(i + a[i]) != m.end()) {
      m[i + a[i]]++;
    } else {
      m.insert({i + a[i], 1LL});
    }
  }
  cout << ans << endl;
}