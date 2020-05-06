#include <iostream>
#include <string>
using namespace std;
int n, a, b[100001], c, visited[100001], cnt, k;
int main() {
  string s;
  cin >> n >> a;
  cin >> s;
  if (s.length() <= 6) {
    k = stoi(s);
  } else {
    k = 1000000;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  while (visited[a] == 0) {
    cnt++;
    visited[a] = 1;
    a = b[a];
    if (k == cnt) {
      cout << a << endl;
      return 0;
    }
  }
  for (int i = 0; i < 7; i++) {
    int x = cnt % 10;
    cnt /= 10;
    for (int j = s.length() - 1 - i; j >= 0; j--) {
      if (s[j] - '0' >= x) {
        s[j] -= x;
        x = 0;
      } else {
        s[j] += 10 - x;
        x = 1;
      }
    }
  }
  c = a;
  while (b[c] != a) {
    cnt++;
    c = b[c];
  }
  cnt++;
  k = 0;
  for (int i = 0; i < s.length(); i++) {
    k *= 10;
    k += s[i] - '0';
    k %= cnt;
  }
  for (int i = 0; i < k; i++) {
    a = b[a];
  }
  cout << a << endl;
}