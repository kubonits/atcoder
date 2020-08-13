#include <algorithm>
#include <cmath>
#include <cstring>
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

int main() {
  int n, cnt;
  ll ans = 0LL;
  map<pair<int, int>, ll> g;
  ll x;
  string s, t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cnt = 0;
    cin >> s;
    t = "";
    int y = -1;
    x = 0;
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == '.') {
        s += "000000000";
        break;
      }
      if (j == s.length() - 1) {
        s += ".000000000";
      }
    }
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == '.') {
        y = 1;
      } else {
        x *= 10LL;
        x += s[j] - '0';
        if (y == 1) {
          cnt++;
          if (cnt == 9) {
            break;
          }
        }
      }
    }
    int a = 0, b = 0;
    while (x % 2 == 0) {
      a++;
      x /= 2LL;
    }
    while (x % 5 == 0) {
      b++;
      x /= 5LL;
    }
    g[{min(a - cnt, 20), min(b - cnt, 20)}]++;
  }
  for (int i = -10; i <= 20; i++) {
    for (int j = -10; j <= 20; j++) {
      for (int k = -10; k <= 20; k++) {
        for (int l = -10; l <= 20; l++) {
          if (g[{i, j}] && g[{k, l}] && i + k >= 0 && j + l >= 0) {
            ans += g[{i, j}] * g[{k, l}];
            if (i == k && j == l) {
              ans -= g[{i, j}];
            }
          }
        }
      }
    }
  }
  cout << ans / 2 << endl;
}