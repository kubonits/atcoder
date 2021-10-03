#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int h, w;
char s[20][21];
int ans = 0, dis[20][20];

void init() {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      dis[i][j] = 10000;
    }
  }
}

void bfs(int x, int y) {
  queue<pair<int, int> > q;
  q.push({x, y});
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    if (p.first > 0 && s[p.first - 1][p.second] == '.' &&
        dis[p.first - 1][p.second] > dis[p.first][p.second] + 1) {
      dis[p.first - 1][p.second] = dis[p.first][p.second] + 1;
      q.push({p.first - 1, p.second});
    }
    if (p.first < h - 1 && s[p.first + 1][p.second] == '.' &&
        dis[p.first + 1][p.second] > dis[p.first][p.second] + 1) {
      dis[p.first + 1][p.second] = dis[p.first][p.second] + 1;
      q.push({p.first + 1, p.second});
    }
    if (p.second > 0 && s[p.first][p.second - 1] == '.' &&
        dis[p.first][p.second - 1] > dis[p.first][p.second] + 1) {
      dis[p.first][p.second - 1] = dis[p.first][p.second] + 1;
      q.push({p.first, p.second - 1});
    }
    if (p.second < w - 1 && s[p.first][p.second + 1] == '.' &&
        dis[p.first][p.second + 1] > dis[p.first][p.second] + 1) {
      dis[p.first][p.second + 1] = dis[p.first][p.second] + 1;
      q.push({p.first, p.second + 1});
    }
  }
}

int main() {
  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      init();
      dis[i][j] = 0;
      if (s[i][j] == '.') {
        bfs(i, j);
        for (int k = 0; k < h; k++) {
          for (int l = 0; l < w; l++) {
            if (s[k][l] == '.') {
              ans = max(ans, dis[k][l]);
            }
          }
        }
      }
    }
  }
  printf("%d\n", ans);
}