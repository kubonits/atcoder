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
  int h, w;
  cin >> h >> w;
  vector<vector<int> > dis(h, vector<int>(w));
  vector<string> s(h);
  queue<pair<int, int> > q;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    for (int j = 0; j < w; j++) {
      dis[i][j] = 1000000000;
    }
  }
  dis[0][0] = 0;
  q.push({0, 0});
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (x != 0 && s[x - 1][y] != s[x][y] && dis[x - 1][y] > dis[x][y] + 1) {
      dis[x - 1][y] = dis[x][y] + 1;
      q.push({x - 1, y});
    }
    if (x != h - 1 && s[x + 1][y] != s[x][y] && dis[x + 1][y] > dis[x][y] + 1) {
      dis[x + 1][y] = dis[x][y] + 1;
      q.push({x + 1, y});
    }
    if (y != 0 && s[x][y - 1] != s[x][y] && dis[x][y - 1] > dis[x][y] + 1) {
      dis[x][y - 1] = dis[x][y] + 1;
      q.push({x, y - 1});
    }
    if (y != w - 1 && s[x][y + 1] != s[x][y] && dis[x][y + 1] > dis[x][y] + 1) {
      dis[x][y + 1] = dis[x][y] + 1;
      q.push({x, y + 1});
    }
  }
  cout << (dis[h - 1][w - 1] == 1000000000 ? -1 : dis[h - 1][w - 1]) << endl;
}
