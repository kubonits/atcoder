#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, ans = "";
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s.substr(i, 6) == "HAGIYA") {
      if (i != 0) {
        ans += s.substr(0, i);
      }
      ans += "HAGIXILE";
      if (i + 6 < n) {
        ans += s.substr(i + 6);
      }
      break;
    }
    }
  cout << ans << endl;
}