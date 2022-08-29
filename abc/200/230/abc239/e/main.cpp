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
vector<vector<int> > g, arr;
vector<int> x;

void dfs(int a, int b) {
  arr[a].push_back(x[a]);
  for (int i = 0; i < g[a].size(); i++) {
    if (g[a][i] != b) {
      dfs(g[a][i], a);
      for (int j = 0; j < arr[g[a][i]].size(); j++) {
        arr[a].push_back(arr[g[a][i]][j]);
      }
      sort(arr[a].begin(), arr[a].end());
      reverse(arr[a].begin(), arr[a].end());
      while (arr[a].size() > 20) {
        arr[a].pop_back();
      }
    }
  }
}
int main() {
  int q, a, b;
  cin >> n >> q;
  x.resize(n + 1);
  g.resize(n + 1);
  arr.resize(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> x[i + 1];
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, 0);
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    cout << arr[a][b - 1] << endl;
  }
}
