#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int d = 0;
  cin >> s;
  if (s == "{}") {
    cout << "dict" << endl;
    return 0;
  }
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '{') {
      d++;
    } else if (s[i] == '}') {
      d--;
    } else if (d == 1 && s[i] == ':') {
      cout << "dict" << endl;
      return 0;
    }
  }
  cout << "set" << endl;
}