#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define MOD 1000000007
using namespace std;
typedef long long ll;
ll sum[200001];
vector<ll> v[2019];
int main() {
  ll ans = 0LL;
  int n;
  string s;
  cin >> s;
  n = s.length();
  reverse(s.begin(), s.end());
  int x = 1;
  v[0].push_back(0);
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + x * (s[i] - '0');
    sum[i + 1] %= 2019;
    v[sum[i + 1]].push_back(1 + i);
    x *= 10;
    x %= 2019;
  }
  for (ll i = 0; i < 2019; i++) {
    if (!v[i].empty()) {
      for (ll j = 0; j < v[i].size(); j++) {
        ans += (ll)(v[i].size() - j - 1);
        /*for (ll k = j + 1; k < v[i].size(); k++) {
          if (v[i][k] - v[i][j] >= 4) {
            ans += (ll)(v[i].size() - k);
          }
        }*/
      }
    }
  }
  cout << ans << endl;
}