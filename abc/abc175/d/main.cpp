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
  int n;
  ll k, cnt, ans = -10000000000, sum;
  cin >> n >> k;
  vector<ll> p(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  for (int j = 0; j < n; j++) {
    cin >> c[j];
  }
  for (int i = 0; i < n; i++) {
    int x = i;
    cnt = 0LL;
    sum = 0LL;
    do {
      cnt++;
      sum += c[p[x]];
      x = p[x];
    } while (x != i);
    if (sum > 0) {
      sum = max(0LL, k / cnt - 1LL) * sum;
      x = i;
      if (max(0LL, k / cnt - 1LL) > 0) {
        ans = max(ans, sum);
      }
      for (int j = 0; j < k - max(0LL, k / cnt - 1LL) * cnt; j++) {
        sum += c[p[x]];
        ans = max(ans, sum);
        x = p[x];
      }
    } else {
      sum = 0;
      x = i;
      for (int j = 0; j < min(k, cnt); j++) {
        sum += c[p[x]];
        ans = max(ans, sum);
        x = p[x];
      }
    }
  }
  cout << ans << endl;
}