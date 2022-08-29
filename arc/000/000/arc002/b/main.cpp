#include <iostream>
#include <string>
using namespace std;
int main() {
  int y, m, d;
  string s;
  cin >> s;
  y = stoi(s.substr(0, 4));
  m = stoi(s.substr(5, 2));
  d = stoi(s.substr(8, 2));
  while (y % m || y / m % d) {
    d++;
    if (d == 32 || d == 31 && (m == 4 || m == 6 || m == 9 || m == 11) ||
        m == 2 && d == 30 ||
        d == 29 && m == 2 && (y % 400 && y % 100 == 0 || y % 4)) {
      d = 1;
      m++;
    }
    if (m == 13) {
      m = 1;
      y++;
    }
  }
  s = to_string(y);
  s += "/";
  if (m / 10 == 0) {
    s += "0";
  }
  s += to_string(m);
  s += "/";
  if (d / 10 == 0) {
    s += "0";
  }
  s += to_string(d);
  cout << s << endl;
}