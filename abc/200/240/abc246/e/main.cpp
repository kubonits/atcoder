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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n, ax, ay, bx, by, x, y, dx[4] = {1, 1, -1, -1}, dy[4] = {1, -1, 1, -1};
  cin >> n;
  cin >> ax >> ay >> bx >> by;
  vector<string> s(n + 2);
  vector<vector<int> > v(n + 1, vector<int>(n + 1));
  vector<vector<vector<int> > > f(n + 1,
                                  vector<vector<int> >(n + 1, vector<int>(4)));
  string t(n + 2, '#');
  s[0] = s[n + 1] = t;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = "#" + s[i] + "#";
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      v[i][j] = 1000000000;
    }
  }
  v[ax][ay] = 0;
  queue<pair<int, int> > q;
  q.push({ax, ay});
  while (!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= 1500; j++) {
        if (s[x + j * dx[i]][y + j * dy[i]] == '.' &&
            f[x + (j - 1) * dx[i]][y + (j - 1) * dy[i]][i] == 0 &&
            v[x + j * dx[i]][y + j * dy[i]] > v[x][y] + 1) {
          v[x + j * dx[i]][y + j * dy[i]] = v[x][y] + 1;
          q.push({x + j * dx[i], y + j * dy[i]});
          f[x + (j - 1) * dx[i]][y + (j - 1) * dy[i]][i]++;
        } else if (s[x + j * dx[i]][y + j * dy[i]] == '#' ||
                   f[x + (j - 1) * dx[i]][y + (j - 1) * dy[i]][i] == 1) {
          // f[x + (j - 1) * dx[i]][y + (j - 1) * dy[i]][i] = 1;
          break;
        } else {
          f[x + (j - 1) * dx[i]][y + (j - 1) * dy[i]][i]++;
        }
      }
    }
  }
  cout << (v[bx][by] == 1000000000 ? -1 : v[bx][by]) << endl;
}
