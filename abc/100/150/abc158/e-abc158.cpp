#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
int n, p, a[100000], u[200001] = {};
string s;
ll ans;
int main() {
  cin >> n >> p >> s;
  if (p == 2 || p == 5) {
    for (int i = 0; i < n; i++) {
      if ((s[i] - '0') % p == 0) {
        ans += (ll)(i + 1);
      }
    }
  } else {
    int num = 1;
    u[n - 1] = s[n - 1] - '0';
    u[n - 1] %= p;
    a[u[n - 1]]++;
    if (u[n - 1] == 0) {
      ans++;
    }
    for (int i = n - 2; i >= 0; i--) {
      num *= 10;
      num %= p;
      u[i] = u[i + 1] + num * (s[i] - '0');
      u[i] %= p;
      if (u[i] == 0) {
        ans++;
      }
      ans += (ll)a[u[i]];
      a[u[i]]++;
    }
  }
  printf("%lld\n", ans);
}