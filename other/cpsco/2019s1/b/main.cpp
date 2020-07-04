#include <iostream>
#include <string>

using namespace std;

int main() {
  int a[26] = {};
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    a[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    for (int j = i + 1; j < 26; j++) {
      if (a[i] && a[j] && a[i] != a[j]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}