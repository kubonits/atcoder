#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
int p[51], flag[51][100001];
int main() {
  int n, m, q, x, y, z, ans;
  cin >> n >> m >> q;
  for (int i = 1; i <= m; i++) {
    p[i] = n;
  }
  for (int i = 0; i < q; i++) {
    cin >> x;
    if (x == 1) {
      cin >> y;
      ans = 0;
      for (int j = 1; j <= m; j++) {
        ans += flag[j][y] * p[j];
      }
      cout << ans << endl;
    } else {
      cin >> y >> z;
      flag[z][y] = 1;
      p[z]--;
    }
  }
}