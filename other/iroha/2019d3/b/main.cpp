#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

string s[20], t[20];

int main() {
  int cnt = 0, a = 0, b = 0;
  set<int> s1, s2;
  cout << "? " << 0 << " " << 1 << " " << 2 << endl;
  cin >> s[0] >> t[0];
  cnt++;
  for (int i = 3; i <= 7; i++) {
    for (int j = i + 1; j <= 7; j++) {
      for (int k = j + 1; k <= 7; k++) {
        cout << "? " << i << " " << j << " " << k << endl;
        cin >> s[cnt] >> t[cnt];
        cnt++;
        if (s[0] == s[cnt - 1]) {
          a++;
          if (s[0] == "Triangle") {
            s1.insert(i);
            s1.insert(j);
            s1.insert(k);
          }
        }
        if (s[0] == t[cnt - 1]) {
          b++;
          if (s[0] == "Triangle") {
            s2.insert(i);
            s2.insert(j);
            s2.insert(k);
          }
        }
      }
    }
  }
  if (s[0] == "Triangle" && a == 4 && b != 4 ||
      s[0] == "Triangle" && a == 4 && b == 4 && s1.size() == 4 ||
      s[0] != "Triangle" && a == 6) {
    cout << "! 1" << endl;
  } else {
    cout << "! 2" << endl;
  }
}