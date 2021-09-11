#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
  int n, m, a[12][12], x, b[12], c[12], ans = 1000000000, cnt;
  cin >> n >> m >> x;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < m; j++) {
      b[j] = 0;
    }
    cnt = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        cnt += c[j];
        for (int k = 0; k < m; k++) {
          b[k] += a[j][k];
        }
      }
    }
    int flag = 1;
    for (int j = 0; j < m; j++) {
      if (b[j] < x) {
        flag = 0;
      }
    }
    if (flag) {
      ans = min(ans, cnt);
    }
  }
  if (ans == 1000000000) {
    ans = -1;
  }
  cout << ans << endl;
}