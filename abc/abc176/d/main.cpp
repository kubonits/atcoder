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
  int h, w, sx, sy, gx, gy, dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
  string s[1000];
  deque<pair<int, int> > q;
  cin >> h >> w >> sx >> sy >> gx >> gy;
  sx--;
  sy--;
  gx--;
  gy--;
  vector<vector<int> > dis(h), visited(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < h; i++) {
    dis[i].resize(w);
    visited[i].resize(w);
    for (int j = 0; j < w; j++) {
      dis[i][j] = 10000000;
    }
  }
  dis[sx][sy] = 0;
  q.push_front({sx, sy});
  while (!q.empty()) {
    int x, y;
    x = q.front().first;
    y = q.front().second;
    q.pop_front();
    if (visited[x][y] == 0) {
      visited[x][y] = 1;
      for (int i = 0; i < 4; i++) {
        if (x + dx[i] >= 0 && x + dx[i] < h && y + dy[i] >= 0 &&
            y + dy[i] < w && dis[x + dx[i]][y + dy[i]] > dis[x][y] &&
            s[x + dx[i]][y + dy[i]] == '.') {
          dis[x + dx[i]][y + dy[i]] = dis[x][y];
          q.push_front({x + dx[i], y + dy[i]});
        }
      }
      for (int i = max(0, x - 2); i < min(h, x + 3); i++) {
        for (int j = max(0, y - 2); j < min(w, y + 3); j++) {
          if (dis[i][j] > dis[x][y] + 1 && s[i][j] == '.') {
            dis[i][j] = dis[x][y] + 1;
            q.push_back({i, j});
          }
        }
      }
    }
  }
  cout << (dis[gx][gy] == 10000000 ? -1 : dis[gx][gy]) << endl;
}