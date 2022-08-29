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
  int h, w, x, y;
  string s[100];
  cin >> h >> w >> x >> y;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  x--;
  y--;
  int ans = 0;
  for (int i = x; i < h; i++) {
    if (s[i][y] == '.') {
      ans++;
    } else {
      break;
    }
  }
  for (int i = x; i >= 0; i--) {
    if (s[i][y] == '.') {
      ans++;
    } else {
      break;
    }
  }
  for (int i = y; i < w; i++) {
    if (s[x][i] == '.') {
      ans++;
    } else {
      break;
    }
  }
  for (int i = y; i >= 0; i--) {
    if (s[x][i] == '.') {
      ans++;
    } else {
      break;
    }
  }
  cout << ans - 3 << endl;
}
