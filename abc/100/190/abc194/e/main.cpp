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
  int n, m, ans = 100000000;
  set<int> s;
  cin >> n >> m;
  vector<int> v(n + 1), a(n);
  for (int i = 0; i <= n; i++) {
    s.insert(i);
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v[a[i]]++;
    if (v[a[i]] == 1) {
      s.erase(a[i]);
    }
    if (i >= m - 1) {
      ans = min(ans, *s.begin());
      v[i - m + 1]--;
      if (v[a[i - m + 1]] == 0) {
        s.insert(a[i - m + 1]);
      }
    }
  }
  cout << ans << endl;
}
