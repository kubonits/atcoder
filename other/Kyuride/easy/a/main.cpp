#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  ll n, m, a[2], b[2], cnt = 2, ans, x;
  cin >> n >> m;
  while (cnt - 1 < n) {
    n -= cnt - 1;
    cnt++;
  }
  a[1] = n;
  a[0] = cnt - a[1];
  cnt = 2;
  while (cnt - 1 < m) {
    m -= cnt - 1;
    cnt++;
  }
  b[1] = m;
  b[0] = cnt - b[1];
  x = a[0] + a[1] + b[0] + b[1];
  ans = (x - 1) * (x - 2) / 2;
  cout << ans + a[1] + b[1] << endl;
}