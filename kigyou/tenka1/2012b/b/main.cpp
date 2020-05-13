#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s, f, b, ss;
  int fl[2] = {1, 1}, flag;
  f = b = "";
  cin >> s;
  vector<string> v;
  while (s.length() != 0 && s.back() == '_') {
    b += "_";
    s.pop_back();
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '_') {
      f = s.substr(0, i);
      s = s.substr(i);
      break;
    }
  }
  if (s == "") {
    cout << f + b << endl;
    return 0;
  }
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '_') {
      fl[0] = 0;
      if (s[i + 1] < 'a' || s[i + 1] > 'z') {
        cout << f + s + b << endl;
        return 0;
      }
    }
    if (s[i] >= 'A' & s[i] <= 'Z') {
      fl[1] = 0;
    }
  }
  if (s[0] < 'a' || s[0] > 'z' || fl[0] == fl[1]) {
    cout << f + s + b << endl;
    return 0;
  }
  if (fl[0]) {
    int flag = 1;
    while (flag) {
      flag = 0;
      for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
          v.push_back(s.substr(0, i));
          s = s.substr(i);
          s[0] += 'a' - 'A';
          flag = 1;
          break;
        }
      }
    }
    cout << f;
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] + "_";
    }
    cout << s + b << endl;
  } else {
    int flag = 1;
    while (flag) {
      flag = 0;
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == '_') {
          v.push_back(s.substr(0, i));
          s = s.substr(i + 1);
          s[0] -= 'a' - 'A';
          flag = 1;
          break;
        }
      }
    }
    cout << f;
    for (int i = 0; i < v.size(); i++) {
      cout << v[i];
    }
    cout << s + b << endl;
  }
}