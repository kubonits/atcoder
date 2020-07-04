#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll n, a[30], b[30], ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    ans += b[i] - a[i];
  }
  sort(a, a + n);
  sort(b, b + n);
  for (int i = 0; i < n; i++) {
    ans += abs(a[i] - a[n / 2]) + abs(b[i] - b[n / 2]);
  }
  cout << ans << endl;
}