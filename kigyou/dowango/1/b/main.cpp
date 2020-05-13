#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
  ll n, p, ans = 0L;
  string s;
  cin >> s;
  n = s.length();
  p = 0LL;
  for (ll i = 0LL; i < n; i++) {
    if ((p - i) % 2 && s[i] != '5' || (p - i) % 2 == 0LL && s[i] != '2') {
      p = i - p;
      p /= 2LL;
      ans += (p + 1LL) * p / 2LL;
      p = i + 1LL;
      if (s[i] == '2') {
        p--;
      }
    }
  }
  p = n - p;
  p /= 2LL;
  ans += (p + 1LL) * p / 2LL;
  cout << ans << endl;
}