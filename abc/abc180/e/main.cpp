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
  int n;
  cin >> n;
  int a[17][17];
  vector<int> x(n), y(n), z(n);
  vector<vector<int> > dis(1 << n), visited(1 << n);
  priority_queue<pair<int, pair<int, int> > > q;
  for (int i = 0; i < (1 << n); i++) {
    dis[i].resize(n);
    visited[i].resize(n);
    for (int j = 0; j < n; j++) {
      dis[i][j] = 1000000000;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]) + max(0, z[j] - z[i]);
    }
  }
  visited[1][0] = 0;
  dis[1][0] = 0;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        dis[i | (1 << k)][k] = min(dis[i | (1 << k)][k], dis[i][j] + a[j][k]);
      }
    }
  }
  cout << dis[(1 << n) - 1][0] << endl;
}