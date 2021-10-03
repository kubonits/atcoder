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
  ll n, ans = 0, x;
  cin >> n;
  vector<ll> a(n), sum(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i + 1] = sum[i] + a[i];
  }
  cin >> x;
  ans += x / sum[n] * n;
  x %= sum[n];
  for (int i = 0; i < n; i++) {
    if (x >= 0) {
      x -= a[i];
      ans++;
    }
  }
  cout << ans << endl;
}
