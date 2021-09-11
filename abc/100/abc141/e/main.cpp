#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
  int n, ans = 0, l, r, mid, flag;
  string s;
  set<string> se;
  cin >> n >> s;
  l = 1;
  r = n / 2;

  while (l <= r) {
    flag = 0;
    mid = (l + r) / 2;
    se.clear();
    for (int j = 0; 2 * mid + j - 1 < n && ans != mid; j++) {
      se.insert(s.substr(j, mid));
      if (se.find(s.substr(mid + j, mid)) != se.end()) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << r << endl;
}