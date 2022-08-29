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
  int n, t, maxi = 0, ans = 0;
  cin >> n;
  string x;
  vector<int> a;
  vector<string> s;
  set<string> m;
  for (int i = 0; i < n; i++) {
    cin >> x >> t;
    if (m.find(x) == m.end()) {
      m.insert(x);
      if (maxi < t) {
        maxi = t;
        ans = i;
      }
    }
  }
  cout << ans + 1 << endl;
}
