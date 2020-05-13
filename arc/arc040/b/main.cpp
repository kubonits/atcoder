#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, r, ans = 0;
  string s, t;
  cin >> n >> r;
  cin >> s;
  while (!s.empty() && s.back() == 'o') {
    s.pop_back();
  }
  if (s.empty()) {
    cout << 0 << endl;
    return 0;
  }
  t = s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    t[i] = 'o';
  }
  for (int i = 0; i <= n - r || i == 0; i++) {
    if (s[i] == '.' || i + r >= n) {
      ans++;
      for (int j = i; j < n && j - i < r; j++) {
        s[j] = 'o';
      }
    }
    if (s == t) {
      break;
    }
    ans++;
  }
  cout << ans << endl;
}