#include <algorithm>
#include <iostream>
using namespace std;

int n, k, a[40], ans;

void dfs(int x, int y, int z) {
  if (x == n && y == k) {
    int res = 0;
    while (z) {
      res += z % 5 + z % 10 / 5;
      z /= 10;
    }
    ans = min(ans, res);
    return;
  }
  if (y < k) {
    dfs(x + 1, y + 1, z + a[x]);
  }
  if (y + n - x >= k) {
    dfs(x + 1, y, z);
  }
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ans = 1000000000;
  dfs(0, 0, 0);
  cout << ans << endl;
}