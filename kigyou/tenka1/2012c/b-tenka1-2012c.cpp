#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int n, flag[4][5] = {};
  map<string, int> m;
  string s, sp = "", h = "", d = "", c = "";
  m.insert({"S", 0});
  m.insert({"H", 1});
  m.insert({"D", 2});
  m.insert({"C", 3});
  m.insert({"1", 0});
  m.insert({"J", 1});
  m.insert({"Q", 2});
  m.insert({"K", 3});
  m.insert({"A", 4});
  cin >> s;
  int i = 0;
  while (i < s.size()) {
    decltype(m)::iterator it = m.find(s.substr(i + 1, 1));
    if (it == m.end()) {
      sp += s.substr(i, 2);
      h += s.substr(i, 2);
      d += s.substr(i, 2);
      c += s.substr(i, 2);
    } else {
      flag[m[s.substr(i, 1)]][m[s.substr(i + 1, 1)]] = 1;
      int flag2 = 1;
      for (int j = 0; j < 5; j++) {
        if (flag[m[s.substr(i, 1)]][j] == 0) {
          flag2 = 0;
        }
      }
      if (flag2) {
        if (s[i] == 'S') {
          if (sp.size()) {
            cout << sp << endl;
          } else {
            cout << 0 << endl;
          }
        } else if (s[i] == 'H') {
          if (h.size()) {
            cout << h << endl;
          } else {
            cout << 0 << endl;
          }
        } else if (s[i] == 'D') {
          if (d.size()) {
            cout << d << endl;
          } else {
            cout << 0 << endl;
          }
        } else if (s[i] == 'C') {
          if (c.size()) {
            cout << c << endl;
          } else {
            cout << 0 << endl;
          }
        }
        return 0;
      }
      if (s[i + 1] == '1') {
        if (s[i] != 'S') {
          sp += s.substr(i, 3);
        }
        if (s[i] != 'D') {
          d += s.substr(i, 3);
        }
        if (s[i] != 'H') {
          h += s.substr(i, 3);
        }
        if (s[i] != 'C') {
          c += s.substr(i, 3);
        }
        i++;
      } else {
        if (s[i] != 'S') {
          sp += s.substr(i, 2);
        }
        if (s[i] != 'D') {
          d += s.substr(i, 2);
        }
        if (s[i] != 'H') {
          h += s.substr(i, 2);
        }
        if (s[i] != 'C') {
          c += s.substr(i, 2);
        }
      }
    }
    i += 2;
  }
}