#include <iostream>

using namespace std;
typedef long long ll;
ll n, a[200000], b[200010], ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  for (int i = 0; i <= n; i++) {
    ans += b[i] * (b[i] - 1LL) / 2LL;
  }
  for (int i = 0; i < n; i++) {
    cout << ans - b[a[i]] + 1LL << endl;
  }
}