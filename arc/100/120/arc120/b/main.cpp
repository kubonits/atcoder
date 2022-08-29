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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int h, w;
  ll ans = 1LL;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < h + w - 1; i++) {
    ll flag = 2LL;
    char c;
    for (int j = max(0, i - h + 1); j < w && i - j >= 0; j++) {
      if (flag == 2 && s[i - j][j] != '.') {
        flag = 1LL;
        c = s[i - j][j];
      } else if (flag == 1 && s[i - j][j] != '.' && s[i - j][j] != c) {
        flag = 0LL;
      }
    }
    ans *= flag;
    ans %= MOD2;
  }
  cout << ans << endl;
}
