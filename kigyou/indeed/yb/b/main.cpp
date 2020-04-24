#include <iostream>
#include <string>
using namespace std;
int main() {
  int n;
  string s, t;
  cin >> s >> t;
  if (s.length() != t.length()) {
    cout << -1 << endl;
    return 0;
  }
  n = s.length();
  for (int i = 0; i < n; i++) {
    int flag = 1;
    for (int j = 0; j < n; j++) {
      if (s[j] != t[(i + j) % n]) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}