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
#define INF 1000000000
using namespace std;
typedef long long ll;
#include <cstring>

int visited[2000];
vector<vector<int> > v;
int ans;

void dfs(int x) {
  visited[x] = 1;
  for (int i = 0; i < v[x].size(); i++) {
    if (visited[v[x][i]] == 0) {
      dfs(v[x][i]);
    }
  }
  ans++;
}

int main() {
  int n, m, a, b;
  cin >> n >> m;
  v.resize(n);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      visited[j] = 0;
    }
    dfs(i);
  }
  cout << ans << endl;
}