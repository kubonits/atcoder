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
int n;
ll sx, sy, gx, gy;
vector<int> visited;
vector<ll> vx, vy, vr;

int dfs(int x) {
  visited[x] = 1;
  if ((gx - vx[x]) * (gx - vx[x]) + (gy - vy[x]) * (gy - vy[x]) ==
      vr[x] * vr[x]) {
    return 1;
  }
  for (int i = 0; i < n; i++) {
    ll dis =
        (vx[x] - vx[i]) * (vx[x] - vx[i]) + (vy[x] - vy[i]) * (vy[x] - vy[i]);
    if (dis <= (vr[i] + vr[x]) * (vr[i] + vr[x]) &&
        dis >= (abs(vr[i] - vr[x])) * (abs(vr[i] - vr[x])) && visited[i] == 0 &&
        dfs(i)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  cin >> n;
  cin >> sx >> sy >> gx >> gy;
  visited.resize(n);
  vx.resize(n);
  vy.resize(n);
  vr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> vx[i] >> vy[i] >> vr[i];
  }
  for (int i = 0; i < n; i++) {
    if ((sx - vx[i]) * (sx - vx[i]) + (sy - vy[i]) * (sy - vy[i]) ==
            vr[i] * vr[i] &&
        visited[i] == 0 && dfs(i)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
