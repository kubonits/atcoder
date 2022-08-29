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
  int n, ans = 2000000000;
  cin >> n;
  vector<int> a(n), sum(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < (1 << n); i++) {
    int x = 0, y = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        x |= a[j];
      } else {
        y ^= x;
        x = a[j];
      }
    }
    y ^= x;
    ans = min(ans, y);
  }
  cout << ans << endl;
}
