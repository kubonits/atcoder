#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int h, w;
char s[100][110];
int g[100][100];

int main() {
  deque<pair<int, int> > d;
  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      g[i][j] = 1000;
    }
  }
  if (s[0][0] == '#') {
    g[0][0] = 1;
  } else {
    g[0][0] = 0;
  }
  d.push_back({0, 0});
  while (!d.empty()) {
    pair<int, int> p = d.front();
    d.pop_front();
    int x = p.first, y = p.second;
    if (x + 1 < h) {
      if ((s[x][y] == s[x + 1][y] || s[x + 1][y] == '.') &&
          g[x + 1][y] > g[x][y]) {
        g[x + 1][y] = g[x][y];
        d.push_front({x + 1, y});
      } else if (s[x][y] != s[x + 1][y] && g[x + 1][y] > g[x][y] + 1) {
        g[x + 1][y] = g[x][y] + 1;
        d.push_back({x + 1, y});
      }
    }
    if (y + 1 < w) {
      if ((s[x][y] == s[x][y + 1] || s[x][y + 1] == '.') &&
          g[x][y + 1] > g[x][y]) {
        g[x][y + 1] = g[x][y];
        d.push_front({x, y + 1});
      } else if (s[x][y + 1] != s[x][y] && g[x][y + 1] > g[x][y] + 1) {
        g[x][y + 1] = g[x][y] + 1;
        d.push_back({x, y + 1});
      }
    }
  }
  printf("%d\n", g[h - 1][w - 1]);
}