#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int h, w, c[6][6], ans;

void dfs(int x, int y, int xx, int yy, int z) {
  int temp;
  temp = c[x][y];
  c[x][y] = c[xx][yy];
  c[xx][yy] = temp;
  int cnt = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cnt += abs(c[i][j] / w - i) + abs(c[i][j] % w - j);
    }
  }
  if (cnt == 0) {
    ans = min(ans, z);
  } else if (cnt / 2 + z < ans) {
    if (x != 0 && xx != x - 1) {
      dfs(x - 1, y, x, y, z + 1);
    }
    if (x != h - 1 && xx != x + 1) {
      dfs(x + 1, y, x, y, z + 1);
    }
    if (y != 0 && yy != y - 1) {
      dfs(x, y - 1, x, y, z + 1);
    }
    if (y != w - 1 && yy != y + 1) {
      dfs(x, y + 1, x, y, z + 1);
    }
  }
  temp = c[x][y];
  c[x][y] = c[xx][yy];
  c[xx][yy] = temp;
}

int main() {
  cin >> h >> w;
  int x, y;
  ans = 24;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> c[i][j];
      c[i][j]--;
      if (c[i][j] < 0) {
        c[i][j] = h * w - 1;
        x = i;
        y = j;
      }
    }
  }
  dfs(x, y, x, y, 0);
  cout << ans << endl;
}