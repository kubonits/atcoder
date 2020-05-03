#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, ans = 0, flag = 1;
  string s;
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      flag = 0;
    }
    if (s[i] == '+') {
      ans += flag;
      flag = 1;
    }
  }
  ans += flag;
  cout << ans << endl;
}