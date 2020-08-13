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

int main() {
  int n, m, d[11][50][50], x, y, z, gx, gy, dx[4] = {-1, 0, 0, 1},
                                            dy[4] = {0, -1, 1, 0};
  string a[50];
  queue<pair<int, pair<int, int> > > q;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        d[i][j][k] = 100000000;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'S') {
        d[0][i][j] = 0;
        q.push({0, {i, j}});
      } else if (a[i][j] == 'G') {
        gx = i;
        gy = j;
      }
    }
  }
  while (!q.empty()) {
    z = q.front().first;
    x = q.front().second.first;
    y = q.front().second.second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m) {
        if (d[z][x + dx[i]][y + dy[i]] > d[z][x][y] + 1) {
          d[z][x + dx[i]][y + dy[i]] = d[z][x][y] + 1;
          q.push({z, {x + dx[i], y + dy[i]}});
        }
        if (a[x + dx[i]][y + dy[i]] == '1' + z &&
            d[z + 1][x + dx[i]][y + dy[i]] > d[z][x][y] + 1) {
          d[z + 1][x + dx[i]][y + dy[i]] = d[z][x][y] + 1;
          q.push({z + 1, {x + dx[i], y + dy[i]}});
        }
      }
    }
  }
  if (d[9][gx][gy] == 100000000) {
    d[9][gx][gy] = -1;
  }
  cout << d[9][gx][gy] << endl;
}