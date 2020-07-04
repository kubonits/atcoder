#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  int n, d;
  cin >> n >> d;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  v.push_back(v.back() + d + 1);
  ll ans = 0LL, p = 1LL;
  for (ll i = 0; i < n; i++) {
    while (v[i] + d >= v[p]) {
      p++;
    }
    if (i + 2 <= p) {
      ans += (p - i - 1LL) * (p - i - 2LL) / 2LL;
    }
  }
  cout << ans << endl;
}