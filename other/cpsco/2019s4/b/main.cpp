#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, d, cnt, ans = 0;
  string s[10];
  cin >> n >> d;
  for (int i = 0; i < d; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < d; i++) {
    for (int j = i + 1; j < d; j++) {
      cnt = 0;
      for (int k = 0; k < n; k++) {
        if (s[i][k] == 'o' || s[j][k] == 'o') {
          cnt++;
        }
      }
      ans = max(ans, cnt);
    }
  }
  cout << ans << endl;
}