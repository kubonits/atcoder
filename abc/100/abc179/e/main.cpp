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
  ll n, x, m, ans = 0LL, a, cnt = 0LL, sum = 0;
  set<ll> s;
  cin >> n >> x >> m;
  a = x;
  do {
    sum += a;
    a = a * a;
    a %= m;
    cnt++;
    if (s.find(a) != s.end()) {
      break;
    }
    s.insert(a);
  } while (cnt < n && a != x);
  if (cnt == n) {
    cout << sum << endl;
  } else {
    ans += sum;
    n -= cnt;
    x = a;
    sum = 0;
    s.clear();
    cnt = 0;
    do {
      sum += a;
      a = a * a;
      a %= m;
      cnt++;
      if (s.find(a) != s.end()) {
        break;
      }
      s.insert(a);
    } while (cnt < n && a != x);
    if (n == cnt) {
      cout << sum + ans << endl;
    } else {
      ans += sum * (n / cnt);
      n -= n / cnt * cnt;
      for (ll i = 0; i < n; i++) {
        ans += a;
        a = a * a;
        a %= m;
      }
      cout << ans << endl;
    }
  }
}