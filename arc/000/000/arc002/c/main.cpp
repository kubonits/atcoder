#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, ans = 1000, cnt;
  string s, x, y, t = "ABXY";
  cin >> n >> s;
  x = "AA";
  y = "BB";
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      x[0] = t[i / 4];
      x[1] = t[i % 4];
      y[0] = t[j / 4];
      y[1] = t[j % 4];
      cnt = 0;
      for (int k = 0; k < n; k++) {
        cnt++;
        if (k < n - 1 && (s.substr(k, 2) == x || s.substr(k, 2) == y)) {
          k++;
        }
      }
      ans = min(ans, cnt);
    }
  }
  cout << ans << endl;
}