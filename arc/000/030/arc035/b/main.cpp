#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main() {
  int n;
  ll t, ans = 1LL, sum = 0LL, ans2 = 0LL;
  vector<ll> v;
  map<ll, ll> m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    v.push_back(t);
    if (m.find(t) == m.end()) {
      m.insert({t, 1LL});
    } else {
      m[t]++;
    }
    ans *= m[t];
    ans %= MOD;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    sum += v[i];
    ans2 += sum;
  }
  cout << ans2 << endl;
  cout << ans << endl;
}