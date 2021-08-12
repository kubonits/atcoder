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

int h, w;
string s[500];

int dfs(int x, int y) {
  if (s[x][y] == 'g') {
    return 1;
  }
  s[x][y] = '#';
  if (x + 1 < h && s[x + 1][y] != '#' && dfs(x + 1, y)) {
    return 1;
  }
  if (x - 1 >= 0 && s[x - 1][y] != '#' && dfs(x - 1, y)) {
    return 1;
  }
  if (y + 1 < w && s[x][y + 1] != '#' && dfs(x, y + 1)) {
    return 1;
  }
  if (y - 1 >= 0 && s[x][y - 1] != '#' && dfs(x, y - 1)) {
    return 1;
  }
  return 0;
}

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  int x, y;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 's') {
        x = i;
        y = j;
      }
    }
  }
  if (dfs(x, y)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}