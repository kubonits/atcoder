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
  int n, k, mini = 1000000000, maxi = 0, ans = 1000000000;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i < k) {
      mini = min(mini, a[i]);
    } else {
      maxi = max(maxi, a[i]);
      b[i] = maxi;
    }
  }
  if (mini >= maxi) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < k; i++) {
    int left = k, right = n - 1, mid;
    while (left <= right) {
      mid = (left + right) / 2;
      if (b[mid] > a[i]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    if (left < n) {
      ans = min(ans, left - i);
    }
  }
  cout << ans << endl;
}
