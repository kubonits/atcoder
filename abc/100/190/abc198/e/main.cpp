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

int n;
vector<int> g[100001], c, m(100001), v;

void dfs(int x, int y) {
  m[c[x]]++;
  if (m[c[x]] == 1) {
    v.push_back(x);
  }
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] != y) {
      dfs(g[x][i], x);
    }
  }
  m[c[x]]--;
}

int main() {
  cin >> n;
  c.resize(n + 1);
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> c[i + 1];
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, 0);
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}
