#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
int main() {
  int n, flag[500][26];
  string s, a[500];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < n; j++) {
      flag[i][a[i][j] - 'a'] = 1;
    }
  }
  s.resize(n);
  for (int i = 0; i < (n + 1) / 2; i++) {
    s[i] = '0';
    for (int j = 0; j < 26; j++) {
      if (flag[i][j] == 1 && flag[n - 1 - i][j] == 1) {
        s[i] = s[n - 1 - i] = j + 'a';
      }
    }
    if (s[i] == '0') {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << s << endl;
}