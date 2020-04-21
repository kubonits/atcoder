#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;
int h, w, k, ans = 1000000;
int dis[800][800];
string s[800];
queue<pair<int, int> > q;
int main() {
  cin >> h >> w >> k;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'S') {
        dis[i][j] = 0;
        q.push({i, j});
      } else {
        dis[i][j] = 1000000;
      }
    }
  }
  while (!q.empty()) {
    int x, y;
    x = q.front().first;
    y = q.front().second;
    q.pop();
    if (dis[x][y] == k + 1) {
      break;
    }
    ans = min(ans, (k - 1 + x) / k);
    ans = min(ans, (k - 1 + y) / k);
    ans = min(ans, (k - 1 + h - 1 - x) / k);
    ans = min(ans, (k - 1 + w - 1 - y) / k);
    if (x != 0 && s[x - 1][y] == '.' && dis[x - 1][y] > dis[x][y] + 1) {
      dis[x - 1][y] = dis[x][y] + 1;
      q.push({x - 1, y});
    }
    if (x != h - 1 && s[x + 1][y] == '.' && dis[x + 1][y] > dis[x][y] + 1) {
      dis[x + 1][y] = dis[x][y] + 1;
      q.push({x + 1, y});
    }
    if (y != 0 && s[x][y - 1] == '.' && dis[x][y - 1] > dis[x][y] + 1) {
      dis[x][y - 1] = dis[x][y] + 1;
      q.push({x, y - 1});
    }
    if (y != w - 1 && s[x][y + 1] == '.' && dis[x][y + 1] > dis[x][y] + 1) {
      dis[x][y + 1] = dis[x][y] + 1;
      q.push({x, y + 1});
    }
  }
  cout << ans + 1 << endl;
}