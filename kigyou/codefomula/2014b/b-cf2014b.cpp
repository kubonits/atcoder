#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int odd = 0, even = 0;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (i % 2 == s.length() % 2) {
      even += s[i] - '0';
    } else {
      odd += s[i] - '0';
    }
  }
  cout << even << " " << odd << endl;
}