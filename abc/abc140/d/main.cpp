#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, cnt1 = 0, cnt2 = 0, k;
  string s;
  cin >> n >> k >> s;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == s[i - 1]) {
      cnt1++;
    } else {
      cnt2++;
    }
  }
  cout << min(n - 1, cnt1 + 2 * k) << endl;
}