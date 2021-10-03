#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  char c;
  int q, n, t, f, flag = 0;
  deque<char> d;
  cin >> s >> q;
  for (int i = 0; i < s.length(); i++) {
    d.push_back(s[i]);
  }
  for (int i = 0; i < q; i++) {
    cin >> t;
    if (t == 1) {
      flag ^= 1;
    } else {
      cin >> f >> c;
      if ((flag + f) % 2) {
        d.push_front(c);
      } else {
        d.push_back(c);
      }
    }
  }
  if (flag) {
    for (int i = d.size() - 1; i >= 0; i--) {
      cout << d[i];
    }
  } else {
    n = d.size();
    for (int i = 0; i < n; i++) {
      cout << d[i];
    }
  }
  cout << endl;
}