#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int ans = 0;
  while (m > 0) {
    ans++;
    m -= v[n - ans];
  }
  cout << ans << endl;
}