#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  ll n, m, l, a, b, ans = 1000000000000000000;
  cin >> n >> m >> l;
  ans = m * l;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    ans = min(ans, a + b * m);
  }
  cout << ans << endl;
}