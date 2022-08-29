#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, l, p;
  string s[20], t;
  getline(cin, t);
  for (int i = 0; i < t.length(); i++) {
    if (t[i] == ' ') {
      n = stoi(t.substr(0, i));
      l = stoi(t.substr(i + 1));
    }
  }
  for (int i = 0; i < l; i++) {
    getline(cin, s[i]);
  }
  getline(cin, t);
  for (int i = 0; i < t.length(); i++) {
    if (t[i] == 'o') {
      p = i;
    }
  }
  for (int i = l - 1; i >= 0; i--) {
    if (p != 0 & s[i][p - 1] == '-') {
      p -= 2;
    } else if (p != 2 * n - 2 && s[i][p + 1] == '-') {
      p += 2;
    }
  }
  cout << p / 2 + 1 << endl;
}