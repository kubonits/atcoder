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
  int h, w;
  deque<pair<int, int> > d;
  string s[500];
  vector<vector<int> > v(500), visited(500);
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    v[i].resize(w);
    visited[i].resize(w);
    for (int j = 0; j < w; j++) {
      v[i][j] = 1000000000;
      visited[i][j] = 0;
    }
  }
  v[0][0] = 0;
  d.push_back({0, 0});
  while (!d.empty()) {
    int x = d[0].first, y = d[0].second;
    d.pop_front();
    if (visited[x][y] == 0) {
      visited[x][y] = 1;
      if (x - 1 >= 0 && s[x - 1][y] == '.' && v[x - 1][y] > v[x][y]) {
        v[x - 1][y] = v[x][y];
        d.push_front({x - 1, y});
      }
      if (x + 1 < h && s[x + 1][y] == '.' && v[x + 1][y] > v[x][y]) {
        v[x + 1][y] = v[x][y];
        d.push_front({x + 1, y});
      }
      if (y - 1 >= 0 && s[x][y - 1] == '.' && v[x][y - 1] > v[x][y]) {
        v[x][y - 1] = v[x][y];
        d.push_front({x, y - 1});
      }
      if (y + 1 < w && s[x][y + 1] == '.' && v[x][y + 1] > v[x][y]) {
        v[x][y + 1] = v[x][y];
        d.push_front({x, y + 1});
      }
      if (x - 2 >= 0) {
        for (int i = max(0, y - 1); i <= min(w - 1, y + 1); i++) {
          if (v[x - 2][i] > v[x][y] + 1) {
            v[x - 2][i] = v[x][y] + 1;
            d.push_back({x - 2, i});
          }
        }
      }
      if (x + 2 < h) {
        for (int i = max(0, y - 1); i <= min(w - 1, y + 1); i++) {
          if (v[x + 2][i] > v[x][y] + 1) {
            v[x + 2][i] = v[x][y] + 1;
            d.push_back({x + 2, i});
          }
        }
      }
      for (int i = max(0, x - 1); i <= min(h - 1, x + 1); i++) {
        for (int j = max(0, y - 2); j <= min(y + 2, w - 1); j++) {
          if (v[i][j] > v[x][y] + 1) {
            v[i][j] = v[x][y] + 1;
            d.push_back({i, j});
          }
        }
      }
    }
  }
  cout << v[h - 1][w - 1];
}