#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, ans = 0;

  string s;
  cin >> s;
  n = s.length();
  for (int i = 0; i < n / 2; i++) {
    if (!(s[i] == 'i' && s[n - 1 - i] == 'i' ||
          s[i] == 'w' && s[n - 1 - i] == 'w' ||
          s[i] == '(' && s[n - 1 - i] == ')' ||
          s[i] == ')' && s[n - 1 - i] == '(')) {
      ans++;
    }
  }
  if (n % 2 && (s[n / 2] == '(' || s[n / 2] == ')')) {
    ans++;
  }
  printf("%d\n", ans);
}