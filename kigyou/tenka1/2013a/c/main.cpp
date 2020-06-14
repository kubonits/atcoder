#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll dp[101][101][64];
int a[1000][1000];
int n, m, ans;
void dfs(int num) {
  int x = num / m;
  int y = num % m;
  if (num == n * m) {
    /*for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j];
      }
      cout << endl;
    }
    cout << endl;*/
    ans++;
    return;
  }
  if ((x == 0 || a[x - 1][y] != 1) && (y == 0 || a[x][y - 1] != 1)) {
    a[x][y] = 1;
    dfs(num + 1);
  }
  int flag = 1;
  for (int i = max(0, x - 2); i < x; i++) {
    if (a[i][y] == 2) {
      flag = 0;
    }
  }
  for (int i = max(0, y - 2); i < y; i++) {
    if (a[x][i] == 2) {
      flag = 0;
    }
  }
  if (flag) {
    a[x][y] = 2;
    dfs(num + 1);
  }
  flag = 1;
  for (int i = max(0, x - 3); i < x; i++) {
    if (a[i][y] == 3) {
      flag = 0;
    }
  }
  for (int i = max(0, y - 3); i < y; i++) {
    if (a[x][i] == 3) {
      flag = 0;
    }
  }
  if (flag) {
    a[x][y] = 3;
    dfs(num + 1);
  }
  return;
}
int main() {
  cin >> n >> m;
  if (n > m) {
    n ^= m;
    m ^= n;
    n ^= m;
  }
  if (n <= 100 && m <= 100) {
    dfs(0);
    cout << ans << endl;
    return 0;
  }
  if (n == 1) {
    if (m % 2) {
      cout << 9 << endl;
    } else if (m % 4 == 0) {
      cout << 10 << endl;
    } else {
      cout << 8 << endl;
    }
    return 0;
  }
  if ((n + m) % 2 == 0) {
    cout << 18 << endl;
  } else if ((n + m) % 4 == 1) {
    cout << 20 << endl;
  } else {
    cout << 16 << endl;
  }
}