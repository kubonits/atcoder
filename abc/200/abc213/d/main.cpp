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

int n, a, b;
vector<int> v[200001];
int visited[200001];

void dfs(int x, int y) {
  cout << x << " ";
  visited[x] = 1;
  while (!v[x].empty()) {
    if (visited[v[x].back()] == 0) {
      dfs(v[x].back(), x);
      cout << x << " ";
    }
    v[x].pop_back();
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    sort(v[i].begin(), v[i].end());
    reverse(v[i].begin(), v[i].end());
  }
  dfs(1, -1);
  cout << endl;
}