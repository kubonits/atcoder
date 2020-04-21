#include <cstdio>
#include <vector>
using namespace std;

int n, x;
int h[101];
vector<int> v[101];

int dfs(int a, int b) {
  int res = 0;
  for (int i = 0; i < v[a].size(); i++) {
    if (v[a][i] != b) {
      res += dfs(v[a][i], a);
    }
  }
  if (res || h[a]) {
    return res + 2;
  }
  return 0;
}

int main() {
  int a, b;
  scanf("%d%d", &n, &x);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &h[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int ans = dfs(x, -1);
  if (ans) {
    ans -= 2;
  }
  printf("%d\n", ans);
}