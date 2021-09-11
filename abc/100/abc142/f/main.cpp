#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, m, a, b, in[1001] = {}, visited[1001], G[1001][1001];
vector<int> g[1001];
vector<int> v, ans;
queue<int> q;

int dfs(int x) {
  int res = 0;

  visited[x] = 1;
  v.push_back(x);
  for (int i = 0; i < g[x].size(); i++) {
    if (visited[g[x][i]] == 1) {
      for (int j = 0; j < v.size(); j++) {
        if (v[j] == g[x][i] || ans.size()) {
          ans.push_back(v[j]);
        }
      }
      int cnt = 0;
      for (int j = 0; j < ans.size(); j++) {
        for (int k = 0; k < ans.size(); k++) {
          cnt += G[ans[j]][ans[k]];
        }
      }
      if (cnt == ans.size()) {
        return 1;
      }
      ans.clear();
    }
    if (visited[g[x][i]] == 0) {
      res = dfs(g[x][i]);
    }
    if (res == 1) {
      return res;
    }
  }
  visited[x] = 2;
  v.pop_back();
  return 0;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    in[b]++;
    G[a][b] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int x = q.front();
    v.push_back(x);
    q.pop();
    for (int i = 0; i < g[x].size(); i++) {
      in[g[x][i]]--;
      if (in[g[x][i]] == 0) {
        q.push(g[x][i]);
      }
    }
  }
  if (v.size() == n) {
    printf("-1\n");
  } else {
    v.clear();
    for (int i = 1; i <= n; i++) {
      if (in[i] && visited[i] == 0 && dfs(i)) {
        printf("%ld\n", ans.size());
        for (int i = 0; i < ans.size(); i++) {
          printf("%d\n", ans[ans.size() - 1 - i]);
        }
        return 0;
      }
    }
  }
}