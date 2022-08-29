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
  int n;
  ll k, x, a;
  priority_queue<ll> q;
  cin >> n >> k >> x;
  for (int i = 0; i < n; i++) {
    cin >> a;
    q.push(a);
  }
  while (!q.empty() && k) {
    a = q.top();
    q.pop();
    if (a >= x) {
      ll y = min(k, a / x);
      a -= y * x;
      k -= y;
      if (a) {
        q.push(a);
      }
    } else {
      k--;
    }
  }
  ll ans = 0LL;
  while (!q.empty()) {
    a = q.top();
    q.pop();
    ans += a;
  }
  cout << ans << endl;
}
