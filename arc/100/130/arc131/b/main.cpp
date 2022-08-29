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

int h, w;
int calc(vector<string> &s, int x, int y, string c) {
  if (x != 0 && s[x - 1].substr(y, 1) == c) {
    return 0;
  }
  if (x != h - 1 && s[x + 1].substr(y, 1) == c) {
    return 0;
  }
  if (y != 0 && s[x].substr(y - 1, 1) == c) {
    return 0;
  }
  if (y != w - 1 && s[x].substr(y + 1, 1) == c) {
    return 0;
  }
  return 1;
}

int main() {
  vector<string> t = {"1", "2", "3", "4", "5"};
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '.') {
        for (int k = 0; k < 5; k++) {
          if (calc(s, i, j, t[k])) {
            s[i][j] = t[k][0];
            break;
          }
        }
      }
    }
    cout << s[i] << endl;
  }
}
