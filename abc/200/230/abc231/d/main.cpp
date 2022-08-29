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

vector<vector<int> > v(100001);
vector<int> visited(100001);
int dfs(int x, int y) {
  if (visited[x] == 1) {
    return 0;
  }
  visited[x] = 1;
  for (int i = 0; i < v[x].size(); i++) {
    if (v[x][i] != y) {
      if (dfs(v[x][i], x) == 0) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int n, m, a, b, cnt = 0;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (v[i].size() > 2) {
      cout << "No" << endl;
      return 0;
    }
    if (visited[i] == 0) {
      if (dfs(i, -1) == 0) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}
