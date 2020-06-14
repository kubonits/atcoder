#include <iostream>
#include <string>
using namespace std;
int main() {
  int ans = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (i % 2) {
      ans -= s[i] - '0';
    } else {
      ans += s[i] - '0';
    }
  }
  cout << ans << endl;
}