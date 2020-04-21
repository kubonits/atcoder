#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s[0] == s.back()) {
    cout << s[0] << endl;
  } else {
    cout << "o" << endl;
  }
}