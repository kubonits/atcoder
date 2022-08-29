#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, ans = 0;
  string s[100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j >= 0; j--) {
      if (s[i][j] == '.') {
        ans++;
        if (i != n - 1) {
          for (int k = j; k < n; k++) {
            s[i + 1][k] = 'o';
          }
        }
        break;
      }
    }
  }
  cout << ans << endl;
}