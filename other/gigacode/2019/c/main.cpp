#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  ll n, a, b, ans = 20000000000, sum[200001] = {};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    sum[i + 1] = sum[i] + a;
  }
  for (int i = 0; i < n; i++) {
    cin >> b;
    if (sum[i + 1] >= b) {
      ans = min(ans, b);
    }
  }
  if (ans != 20000000000) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
}