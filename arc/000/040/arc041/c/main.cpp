#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll x[100000];
string s[100000];
int main() {
  ll n, l, ans = 0LL, p;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> s[i];
  }
  p = l;
  if (s[n - 1] == "R") {
    ans += l - x[n - 1];
    x[n - 1] = l;
    p = l - 1LL;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == "R" && s[i + 1] == "R") {
      ans += p - x[i];
      x[i] = p;
      p--;
    } else if (s[i] == "R") {
      p = x[i] - 1LL;
    }
  }
  p = 1LL;
  if (s[0] == "L") {
    ans += x[0] - p;
    x[0] = p;
    p++;
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == "L" && s[i - 1] == "L") {
      ans += x[i] - p;
      x[i] = p;
      p++;
    } else if (s[i] == "L") {
      p = x[i] + 1LL;
    }
  }
  p = 0;
  while (p < n) {
    ll l = 0LL, r = 0LL;
    while (p < n && s[p] == "R") {
      p++;
      r++;
    }
    while (p < n && s[p] == "L") {
      p++;
      l++;
    }
    if (p >= l && l && r) {
      ans += max(l, r) * (x[p - l] - x[p - l - 1LL] - 1LL);
    }
  }
  cout << ans << endl;
}