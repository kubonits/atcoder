#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;
int n, ans[200010];
int a[200010], dp[200010], parent[200010];
vector<int> G[200010];
stack<pair<int, int> > st;
int cnt;
int depth;
void dfs(int x, int y) {
  int l, r, mid;
  int flag = 0;
  l = 1;
  r = n;
  while (l <= r) {
    mid = (l + r) / 2;
    if (dp[mid] < a[x]) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  st.push({l, dp[l]});
  parent[x] = dp[l];
  dp[l] = a[x];
  ans[x] = l;
  l = 0;
  r = n;
  while (l <= r) {
    mid = (l + r) / 2;
    if (dp[mid] != 1000000001) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  ans[x] = r;
  for (int i = 0; i < G[x].size(); i++) {
    if (G[x][i] != y) {
      dfs(G[x][i], x);
    }
  }
  dp[st.top().first] = st.top().second;
  st.pop();
}

int main() {
  int u, v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1; i <= n + 2; i++) {
    dp[i] = 1000000001;
  }
  dp[0] = 0;
  dfs(1, -1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
}