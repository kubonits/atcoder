#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int f[100], ans = 10, cnt, l, t;

  string s;
  cin >> s;
  l = s.length();
  for (int i = 0; i < 1024; i++) {
    t = 0;
    for (int j = 0; j < 100; j++) {
      f[j] = 0;
    }
    cnt = 0;
    for (int j = 0; j < 10; j++) {
      if (i & (1 << j)) {
        cnt++;
        t = j;
        for (int k = 0; k + j < 100; k++) {
          if (s[k % l] == 'o') {
            f[j + k] = 1;
          }
        }
      }
    }
    int flag = 1;
    for (int j = t; j < 100; j++) {
      if (f[j] == 0) {
        flag = 0;
      }
    }
    if (flag) {
      ans = min(ans, cnt);
    }
  }
  cout << ans << endl;
}