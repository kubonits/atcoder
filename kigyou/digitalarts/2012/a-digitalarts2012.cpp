#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string l, t;
  int n;
  vector<string> s;
  getline(cin, l);
  for (int i = l.length() - 1; i >= 0; i--) {
    if (l[i] == ' ') {
      s.push_back(l.substr(i + 1));
      l = l.substr(0, i);
    }
  }
  s.push_back(l);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    for (int j = 0; j < s.size(); j++) {
      if (t.length() == s[j].length()) {
        int flag = 1;
        for (int k = 0; k < t.length(); k++) {
          if (t[k] != '*' && t[k] != s[j][k]) {
            flag = 0;
          }
        }
        if (flag) {
          for (int k = 0; k < s[j].length(); k++) {
            s[j][k] = '*';
          }
        }
      }
    }
  }
  for (int i = s.size() - 1; i >= 0; i--) {
    cout << s[i] << " ";
  }
  cout << endl;
}