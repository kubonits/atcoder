#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
vector<pair<int, int> > e;
int n, a[100001] = {};
string s;

int main() {
  int cnt = 0, p;
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      a[i + 1] = 1;
      cnt++;
    }
  }
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 2 - i]) {
      printf("-1\n");
      return 0;
    }
  }
  if (s[n - 1] == '1' || s[0] == '0') {
    printf("-1\n");
    return 0;
  }
  p = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == '1') {
      while (p < i + 1) {
        cout << i + 1 << " " << p << endl;
        p++;
      }
    }
  }
  cout << p << " " << n << endl;
}