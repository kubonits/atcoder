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

int main() {
  ll h, w, ans = 0LL, cnt, l, r, cnt2 = 0LL;
  string s[2000];
  vector<vector<ll> > a;
  vector<ll> x(4000001);
  cin >> h >> w;
  a.resize(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    a[i].resize(w);
  }
  x[0] = 1LL;
  for (int i = 1; i <= 4000000; i++) {
    x[i] = x[i - 1] * 2LL;
    x[i] %= MOD;
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '.') {
        cnt2++;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    l = 0;
    cnt = 0LL;
    for (int j = 0; j <= w; j++) {
      if (j != w && s[i][j] == '.') {
        cnt++;
      } else {
        for (int k = l; k < j; k++) {
          a[i][k] += cnt;
        }
        l = j + 1;
        cnt = 0LL;
      }
    }
  }
  for (int i = 0; i < w; i++) {
    l = 0;
    cnt = 0LL;
    for (int j = 0; j <= h; j++) {
      if (j != h && s[j][i] == '.') {
        cnt++;
      } else {
        for (int k = l; k < j; k++) {
          a[k][i] += cnt;
        }
        l = j + 1;
        cnt = 0LL;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '.') {
        a[i][j]--;
        ans += (x[a[i][j]] + MOD - 1LL) * x[cnt2 - a[i][j]] % MOD;
        ans %= MOD;
      }
    }
  }
  cout << ans << endl;
}