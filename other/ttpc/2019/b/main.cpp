#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, flag;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    flag = 0;
    for (int i = 0; i + 3 < s.length(); i++) {
      if (s.substr(i, 4) == "okyo") {
        for (int j = i + 4; j + 2 < s.length(); j++) {
          if (s.substr(j, 3) == "ech") {
            flag = 1;
          }
        }
      }
    }
    if (flag) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}