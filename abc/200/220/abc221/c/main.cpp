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
  string s;
  string a, b;
  ll ans = 0LL, x, y;
  cin >> s;
  for (int i = 0; i < (1 << s.length()); i++) {
    a = b = "";
    for (int j = 0; j < s.length(); j++) {
      if (i & (1 << j)) {
        a += s.substr(j, 1);
      } else {
        b += s.substr(j, 1);
      }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.length() && b.length()) {
      x = stoi(a);
      y = stod(b);
      ans = max(ans, x * y);
    }
  }
  cout << ans << endl;
}
