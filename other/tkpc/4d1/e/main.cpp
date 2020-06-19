#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int n, m, k;
  ll e;
  cin >> n >> m >> k >> e;
  vector<ll> a(n), b(m), suma(n + 1), sumb(m + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  suma[0] = 0;
  sumb[0] = e;
  for (int i = 0; i < n; i++) {
    suma[i + 1] = suma[i] + a[i];
  }
  for (int i = 0; i < k; i++) {
    sumb[i + 1] = sumb[i] + b[m - 1 - i];
  }
  if (suma[n] <= sumb[k]) {
    cout << "Yes" << endl;
    for (int i = 0; i <= k; i++) {
      if (suma[n] <= sumb[i]) {
        cout << i << endl;
        return 0;
      }
    }
  } else {
    cout << "No" << endl;
    for (int i = n; i >= 0; i--) {
      if (suma[i] <= sumb[k]) {
        cout << i << endl;
        return 0;
      }
    }
  }
}