#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int a[26] = {}, n, m, b[26] = {}, ans = 0;
  string s, t;
  cin >> n >> m >> s >> t;
  for (int i = 0; i < m; i++) {
    a[t[i] - 'A']++;
  }
  for (int i = 0; i < n; i++) {
    b[s[i] - 'A']++;
  }
  for (int i = 0; i < 26; i++) {
    if (b[i]) {
      if (!a[i]) {
        cout << -1 << endl;
        return 0;
      } else {
        ans = max(ans, (b[i] + a[i] - 1) / a[i]);
      }
    }
  }
  cout << ans << endl;
}
