#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, a[51][3] = {};
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      a[i + 1][j] = a[i][j];
    }
    if (s[i] == 'R') {
      a[i + 1][0] ^= 1;
    } else if (s[i] == 'G') {
      a[i + 1][1] ^= 1;
    } else {
      a[i + 1][2] ^= 1;
    }
  }
  cout << a[n][0] + a[n][1] + a[n][2] << endl;
}