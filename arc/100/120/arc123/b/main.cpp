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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  sort(c.begin(), c.end());
  int x, y, z, ans;
  x = y = z = ans = 0;
  while (x < n && y < n && z < n) {
    if (a[x] < b[y] && b[y] < c[z]) {
      x++;
      y++;
      z++;
      ans++;
    } else if (a[x] >= b[y]) {
      y++;
    } else if (a[x] >= c[z] || b[y] >= c[z]) {
      z++;
    }
  }
  cout << ans << endl;
}
