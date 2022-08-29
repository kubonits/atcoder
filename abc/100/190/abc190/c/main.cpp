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

int main() {
  int n, m, k, ans = 0;
  cin >> n >> m;
  vector<int> a(m), b(m), f(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
  }
  cin >> k;
  vector<int> c(k), d(k);
  for (int i = 0; i < k; i++) {
    cin >> c[i] >> d[i];
  }
  for (int i = 0; i < (1 << k); i++) {
    for (int j = 1; j <= n; j++) {
      f[j] = 0;
    }
    for (int j = 0; j < k; j++) {
      if (i & (1 << j)) {
        f[c[j]] = 1;
      } else {
        f[d[j]] = 1;
      }
    }
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      if (f[a[j]] && f[b[j]]) {
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}
