#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n, q, mind, maxd, d;
  string s;
  cin >> q;
  while (q--) {
    cin >> s;
    n = s.length();
    d = mind = maxd = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        d++;
      } else {
        d--;
      }
      mind = min(mind, d);
      maxd = max(maxd, d);
    }
    cout << (d == 0 && mind >= -n / 4 && maxd <= n / 4 ? "Yes" : "No") << endl;
  }
}