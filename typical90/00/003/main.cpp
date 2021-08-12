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

int dis[100001];
vector<vector<int>> v(100001);

void dfs(int x, int y, int z) {
  dis[x] = z;
  for (int i = 0; i < v[x].size(); i++) {
    if (v[x][i] != y) {
      dfs(v[x][i], x, z + 1);
    }
  }
}

int main() {
  int n, a, b;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 0; i <= n; i++) {
    dis[i] = 0;
  }
  dis[1] = 0;
  dfs(1, -1, 0);
  int maxi = -1, p = -1;
  for (int i = 1; i <= n; i++) {
    if (dis[i] > maxi) {
      maxi = dis[i];
      p = i;
    }
  }
  dfs(p, -1, 0);
  for (int i = 1; i <= n; i++) {
    maxi = max(maxi, dis[i]);
  }
  cout << maxi + 1 << endl;
}