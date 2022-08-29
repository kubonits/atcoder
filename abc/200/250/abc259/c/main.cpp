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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int p = 0;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == t[p]) {
      p++;
    } else if (i > 1) {
      while (s[i - 1] == t[p] && s[i - 2] == t[p]) {
        p++;
      }
      if (s[i] == t[p]) {
        p++;
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  while (p < t.length()) {
    if (s[s.length() - 1] == t[p] && s[s.length() - 2] == t[p]) {
      p++;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
