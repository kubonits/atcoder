#include <iostream>
#include <string>
using namespace std;

int l[100000], r[100000];
int main() {
  string s;
  int n;
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      r[i + 1] = r[i] + 1;
      r[i] = 0;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'L') {
      l[i - 1] = l[i] + 1;
      l[i] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int ans = 0;
    if (s[i] == 'R') {
      ans += (l[i]) / 2 + (r[i + 1] + 1) / 2;
    } else {
      ans += (r[i]) / 2 + (l[i - 1] + 1) / 2;
    }
    cout << ans << " ";
  }
  cout << endl;
}