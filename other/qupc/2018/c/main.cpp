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
  int h, w, x;
  queue<pair<int, int> > q;
  string s[1000];
  cin >> h >> w >> x;
  vector<vector<int> > dis(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < h; i++) {
    dis[i].resize(w);
    for (int j = 0; j < w; j++) {
      dis[i][j] = s[i][j] == '@' ? 0 : 10000000;
      if (s[i][j] == '@') {
        q.push({i, j});
      }
    }
  }
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    if (p.first - 1 >= 0 && s[p.first - 1][p.second] != '#' &&
        dis[p.first - 1][p.second] > dis[p.first][p.second] + 1) {
      dis[p.first - 1][p.second] = dis[p.first][p.second] + 1;
      q.push({p.first - 1, p.second});
    }
    if (p.first + 1 < h && s[p.first + 1][p.second] != '#' &&
        dis[p.first + 1][p.second] > dis[p.first][p.second] + 1) {
      dis[p.first + 1][p.second] = dis[p.first][p.second] + 1;
      q.push({p.first + 1, p.second});
    }
    if (p.second - 1 >= 0 && s[p.first][p.second - 1] != '#' &&
        dis[p.first][p.second - 1] > dis[p.first][p.second] + 1) {
      dis[p.first][p.second - 1] = dis[p.first][p.second] + 1;
      q.push({p.first, p.second - 1});
    }
    if (p.second + 1 < w && s[p.first][p.second + 1] != '#' &&
        dis[p.first][p.second + 1] > dis[p.first][p.second] + 1) {
      dis[p.first][p.second + 1] = dis[p.first][p.second] + 1;
      q.push({p.first, p.second + 1});
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'S') {
        q.push({i, j});
        dis[i][j] = 0;
      } else if (s[i][j] == '#' || s[i][j] == '@' || dis[i][j] <= x) {
        dis[i][j] = -1;
      } else {
        dis[i][j] = 10000000;
      }
    }
  }
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    if (p.first - 1 >= 0 && dis[p.first - 1][p.second] != -1 &&
        dis[p.first - 1][p.second] > dis[p.first][p.second] + 1) {
      dis[p.first - 1][p.second] = dis[p.first][p.second] + 1;
      q.push({p.first - 1, p.second});
    }
    if (p.first + 1 < h && dis[p.first + 1][p.second] != -1 &&
        dis[p.first + 1][p.second] > dis[p.first][p.second] + 1) {
      dis[p.first + 1][p.second] = dis[p.first][p.second] + 1;
      q.push({p.first + 1, p.second});
    }
    if (p.second - 1 >= 0 && dis[p.first][p.second - 1] != -1 &&
        dis[p.first][p.second - 1] > dis[p.first][p.second] + 1) {
      dis[p.first][p.second - 1] = dis[p.first][p.second] + 1;
      q.push({p.first, p.second - 1});
    }
    if (p.second + 1 < w && dis[p.first][p.second + 1] != -1 &&
        dis[p.first][p.second + 1] > dis[p.first][p.second] + 1) {
      dis[p.first][p.second + 1] = dis[p.first][p.second] + 1;
      q.push({p.first, p.second + 1});
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'G') {
        cout << (dis[i][j] != 10000000 ? dis[i][j] : -1) << endl;
      }
    }
  }
}