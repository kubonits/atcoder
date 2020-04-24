#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  string s;
  cin >> s;
  n = s.length();
  for (int i = 0; i <= (n - 1) / 2 - 1 - i; i++) {
    if (s[i] != s[(n - 1) / 2 - 1 - i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 0; i < n / 2 - 1 - i; i++) {
    if (s[(n + 3) / 2 - 1 + i] != s[n - 1 - i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 1 - i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}