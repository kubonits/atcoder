#include <iostream>
#include <string>
using namespace std;
int main() {
  int n;
  string s;
  cin >> s;
  n = s.length();
  if (s == "a" || s == "zzzzzzzzzzzzzzzzzzzz") {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (s[i] != s[j]) {
        s[i] ^= s[j];
        s[j] ^= s[i];
        s[i] ^= s[j];
        cout << s << endl;
        return 0;
      }
    }
  }
  if (s[0] == 'a') {
    s.pop_back();
    s.pop_back();
    s += "b";
    cout << s << endl;
  } else if (s[0] == 'z') {
    s[0] = 'y';
    s += "a";
    cout << s << endl;
  } else if (s.length() != 20) {
    s[0]--;
    s += "a";
    cout << s << endl;
  } else {
    s[0]++;
    s[1]--;
    cout << s << endl;
  }
}