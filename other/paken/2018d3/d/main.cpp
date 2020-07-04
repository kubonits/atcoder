#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll l[100000], r[100000], a[100000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  l[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    l[i + 1] = max(0LL, l[i] + a[i]);
  }
  r[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    r[i] = max(0LL, r[i + 1] + a[i]);
  }
  for (int i = 0; i < n; i++) {
    cout << max(l[i], r[i]) << endl;
  }
}