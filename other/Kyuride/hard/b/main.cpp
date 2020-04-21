#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, a[10], b[7] = {}, cnt = 0;
  string s[100];
  cin >> n;
  for (int i = 0; i < 10; i++) {
    cin >> a[i];
  }
  sort(a, a + 10);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 7; i++) {
    cnt = 0;
    for (int j = 0; j < n; j++) {
      if (s[j][i] == 'X') {
        cnt++;
      } else {
        b[i] = max(b[i], cnt);
        cnt = 0;
      }
    }
    b[i] = max(b[i], cnt);
  }
  sort(b, b + 7);
  for (int i = 0; i < 7; i++) {
    if (a[i + 3] < b[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}