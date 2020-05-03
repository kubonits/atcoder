#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int ans, x[10];
int n, m, q, a[50], b[50], c[50], d[50];

void dfs(int y, int z) {
  if (y == n) {
    int cnt = 0;
    for (int i = 0; i < q; i++) {
      if (x[b[i] - 1] - x[a[i] - 1] == c[i]) {
        cnt += d[i];
      }
    }
    ans = max(ans, cnt);
    return;
  }
  for (int i = z; i <= m; i++) {
    x[y] = i;
    dfs(y + 1, i);
  }
}

int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  dfs(0, 1);
  cout << ans << endl;
}