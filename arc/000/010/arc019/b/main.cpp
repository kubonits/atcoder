#include <iostream>
#include <string>
using namespace std;
int n, ans, flag[300000], cnt;
int main() {
  string s;
  cin >> s;
  n = s.length();
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < (n + 1) / 2; i++) {
    if (s[i] == s[n - 1 - i]) {
      flag[i] = 1;
      cnt++;
    }
  }
  for (int i = 0; i < (n) / 2; i++) {
    if (s[i] == s[n - 1 - i]) {
      ans += 50;
    } else if (cnt < (n + 1) / 2 - 1) {
      ans += 50;
    } else {
      ans += 48;
    }
  }
  if (n % 2 == 1 && cnt < (n + 1) / 2) {
    ans += 25;
  }
  cout << ans << endl;
}