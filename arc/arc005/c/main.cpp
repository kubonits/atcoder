#include <deque>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int d[500][500];
int main() {
  int h, w, gx, gy;
  string s[500];
  deque<pair<int, int> > dq;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 's') {
        d[i][j] = 0;
        dq.push_back({i, j});
      } else {
        d[i][j] = 1000000000;
      }
      if (s[i][j] == 'g') {
        gx = i;
        gy = j;
      }
    }
  }
  while (!dq.empty()) {
    int x, y;
    x = dq.front().first;
    y = dq.front().second;
    dq.pop_front();
    if (x != 0 && s[x - 1][y] == '#' && d[x - 1][y] > d[x][y] + 1) {
      d[x - 1][y] = d[x][y] + 1;
      dq.push_back({x - 1, y});
    } else if (x != 0 && s[x - 1][y] != '#' && d[x - 1][y] > d[x][y]) {
      d[x - 1][y] = d[x][y];
      dq.push_front({x - 1, y});
    }
    if (x != h - 1 && s[x + 1][y] == '#' && d[x + 1][y] > d[x][y] + 1) {
      d[x + 1][y] = d[x][y] + 1;
      dq.push_back({x + 1, y});
    } else if (x != h - 1 && s[x + 1][y] != '#' && d[x + 1][y] > d[x][y]) {
      d[x + 1][y] = d[x][y];
      dq.push_front({x + 1, y});
    }
    if (y != 0 && s[x][y - 1] == '#' && d[x][y - 1] > d[x][y] + 1) {
      d[x][y - 1] = d[x][y] + 1;
      dq.push_back({x, y - 1});
    } else if (y != 0 && s[x][y - 1] != '#' && d[x][y - 1] > d[x][y]) {
      d[x][y - 1] = d[x][y];
      dq.push_front({x, y - 1});
    }
    if (y != w - 1 && s[x][y + 1] == '#' && d[x][y + 1] > d[x][y] + 1) {
      d[x][y + 1] = d[x][y] + 1;
      dq.push_back({x, y + 1});
    } else if (y != w - 1 && s[x][y + 1] != '#' && d[x][y + 1] > d[x][y]) {
      d[x][y + 1] = d[x][y];
      dq.push_front({x, y + 1});
    }
  }
  if (d[gx][gy] <= 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}