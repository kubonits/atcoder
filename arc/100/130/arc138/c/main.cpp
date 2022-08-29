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
  int n, p = 0, mini = 1;
  ll ans = 0;
  cin >> n;
  vector<ll> a(n), b(n), c(n), sum(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b.begin(), b.end());
  for (int i = n / 2; i < n; i++) {
    ans += b[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] <= b[n / 2 - 1]) {
      c[i] = 1;
    } else {
      c[i] = -1;
    }
    sum[i + 1] = sum[i] + c[i];
    if (mini > sum[i + 1]) {
      p = (i + 1) % n;
      mini = sum[i + 1];
    }
  }
  cout << p << " " << ans << endl;
}
