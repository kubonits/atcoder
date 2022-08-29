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
  ll n, w, a, b, ans = 0LL;
  priority_queue<pair<ll, ll> > q;
  cin >> n >> w;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    q.push({a, b});
  }
  for (int i = 0; i < n; i++) {
    a = q.top().first;
    b = q.top().second;
    q.pop();
    ans += a * min(w, b);
    w -= min(w, b);
  }
  cout << ans << endl;
}
