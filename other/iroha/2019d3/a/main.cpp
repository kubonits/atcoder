#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  ll a[26];
  vector<ll> v = {6, 28, 496, 8128, 33550336, 8589869056};
  string s[9] = {"",      "a",      "aa",      "aaa",     "aaai",
                 "aaaji", "aabaji", "agabaji", "dagabaji"};
  for (int i = 0; i < 26; i++) {
    cin >> a[i];
  }
  cout << a[0] - a[1] << endl;
  cout << a[2] + a[3] << endl;
  cout << max(0LL, a[5] + 1LL - a[4]) << endl;
  cout << (a[6] + a[7] + a[8]) / 3 + 1 << endl;
  cout << s[a[9]] << endl;
  for (int i = 0; i < 3600; i++) {
    if (i % 59 == a[10] && i % 61 == a[11]) {
      a[10] = i + 59 * 61 * (a[12] - 1);
    }
  }
  for (int i = 0; i < v.size(); i++) {
    if (abs(a[10] - v[i]) >= a[13]) {
      cout << min(v[i], a[10]) << endl;
      cout << max(v[i], a[10]) << endl;
      break;
    }
  }
  ll ans = (a[14] + a[15] + a[16]) * (a[17] + a[18] + a[19]) % 9973;
  ans *= (a[20] + a[21] + a[22]);
  ans %= 9973;
  ans *= (a[23] + a[24] + a[25]);
  ans %= 9973;
  cout << ans % 9973 << endl;
}