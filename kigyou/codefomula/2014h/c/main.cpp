#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s;
  getline(cin, s);
  int l = s.length();
  vector<string> v;
  for (int i = 0; i < l; i++) {
    if (s[i] == '@') {
      for (int j = i + 1; j < l; j++) {
        if (s[j] == ' ' || s[j] == '@') {
          if (j != i + 1) {
            v.push_back(s.substr(i + 1, j - i - 1));
          }
          break;
        }
        if (j == l - 1) {
          v.push_back(s.substr(i + 1));
        }
      }
    }
  }
  if (!v.empty()) {
    sort(v.begin(), v.end());
    cout << v[0] << endl;
    for (int i = 1; i < v.size(); i++) {
      if (v[i] != v[i - 1]) {
        cout << v[i] << endl;
      }
    }
  }
}