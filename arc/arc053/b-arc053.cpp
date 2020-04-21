#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int n, cnt[26] = {}, num = 0;
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    num += cnt[i] % 2;
  }
  if (num == 0 || num == 1) {
    cout << n << endl;
  } else {
    cout << (n - num) / 2 / num * 2 + 1 << endl;
  }
}