#include <algorithm>
#include <cmath>
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
int h, w;
string s[10], ans;

bool solve(int x, int y) {
  if (x == 0) {
    return true;
  }
  if (y != 0 && s[x - 1][y - 1] == '.' && solve(x - 1, y - 1)) {
    ans += "L";
    return true;
  }
  if (s[x - 1][y] == '.' && solve(x - 1, y)) {
    ans += "S";
    return true;
  }
  if (y != w - 1 && s[x - 1][y + 1] == '.' && solve(x - 1, y + 1)) {
    ans += "R";
    return true;
  }
  return false;
}

int main() {
  int x, y;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 's') {
        x = i;
        y = j;
      }
    }
  }
  if (solve(x, y) == false) {
    cout << "impossible" << endl;
  } else {
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
}