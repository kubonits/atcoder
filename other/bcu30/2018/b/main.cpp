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

int h, w, sx, sy, a[500][500], dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
string s[500];
void dfs(int x, int y) {
  int mini = a[x][y], p = -1;
  s[x][y] = 'W';
  for (int i = 0; i < 4; i++) {
    if (x + dx[i] >= 0 && x + dx[i] < h && y + dy[i] >= 0 && y + dy[i] < w &&
        mini > a[x + dx[i]][y + dy[i]]) {
      p = i;
      mini = a[x + dx[i]][y + dy[i]];
    }
  }
  if (p != -1) {
    dfs(x + dx[p], y + dy[p]);
  }
}
int main() {
  cin >> h >> w >> sx >> sy;
  sx--;
  sy--;
  for (int i = 0; i < h; i++) {
    s[i] = string(w, '.');
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  dfs(sx, sy);
  for (int i = 0; i < h; i++) {
    cout << s[i] << endl;
  }
}