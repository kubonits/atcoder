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
  int n, cnt = 0, t = 0, pre, x = 0, y = 0, z = 0;
  cin >> n;
  vector<int> a(n), b(n), ans(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    b[i] += a[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  a.push_back(2000000001);
  b.push_back(2000000001);
  pre = 1;
  t = a[0];
  while (x < n || y < n) {
    while (a[x] == t || b[y] == t) {
      if (a[x] == t) {
        cnt++;
        x++;
      }
      if (b[y] == t) {
        cnt--;
        y++;
      }
    }
    ans[z] += t - pre;
    z = cnt;
    pre = t;
    t = min(a[x], b[y]);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
