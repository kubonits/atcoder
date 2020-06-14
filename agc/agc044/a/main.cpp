#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

ll ans, a, b, c, d;
ll dis[100001];
map<ll, ll> m;
ll dfs(ll x, ll y) {
  ll res = 1000000000000000000;
  ll num;
  if (m.find(x) != m.end()) {
    ans = min(ans, y + m[x]);
    return m[x];
  }
  if (1000000000000000000 / d > x) {
    res = x * d;
    ans = min(ans, y + x * d);
  }
  if (x == 100000LL) {
    ans = min(ans, y + m[x]);
    return m[x];
  }
  if (x % 5LL == 0LL) {
    dfs(x / 5LL, y + c);
    res = min(res, m[x / 5LL] + c);
  } else {
    dfs((x + 5LL - x % 5LL) / 5LL, y + (5LL - x % 5LL) * d + c);
    res = min(res, m[(x + 5LL - x % 5LL) / 5LL] + (5LL - x % 5LL) * d + c);
    dfs((x - x % 5LL) / 5LL, y + x % 5LL * d + c);
    res = min(res, m[(x - x % 5LL) / 5LL] + x % 5LL * d + c);
  }
  if (x % 3LL == 0LL) {
    dfs(x / 3LL, y + b);
    res = min(res, m[x / 3LL] + b);
  } else {
    dfs((x + 3LL - x % 3LL) / 3LL, y + (3LL - x % 3LL) * d + b);
    res = min(res, m[(x + 3LL - x % 3LL) / 3LL] + (3LL - x % 3LL) * d + b);
    dfs((x - x % 3LL) / 3LL, y + x % 3LL * d + b);
    res = min(res, m[(x - x % 3LL) / 3LL] + x % 3LL * d + b);
  }
  if (x % 2LL == 0LL) {
    dfs(x / 2LL, y + a);
    res = min(res, m[x / 2LL] + a);
  } else {
    dfs((x + 1LL) / 2LL, y + d + a);
    res = min(res, m[(x + 1LL) / 2LL] + d + a);
    dfs((x - 1LL) / 2LL, y + d + a);
    res = min(res, m[(x - 1LL) / 2LL] + d + a);
  }
  ans = min(ans, res + y);
  m.insert({x, res});
  return res;
}

int main() {
  ll n, t;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b >> c >> d;
    ans = 100000000000000000;
    m.clear();
    for (int i = 1LL; i <= 100000; i++) {
      dis[i] = 1000000000000000000;
    }
    while (!q.empty()) {
      q.pop();
    }
    q.push({0LL, 0LL});
    while (!q.empty()) {
      ll x, y;
      x = q.top().second;
      y = q.top().first;
      q.pop();
      if (dis[x] == y) {
        if (x - 1LL >= 0 && dis[x - 1LL] > y + d) {
          q.push({y + d, x - 1LL});
          dis[x - 1LL] = y + d;
        }
        if (x + 1LL <= 100000LL && dis[x + 1LL] > y + d) {
          q.push({y + d, x + 1LL});
          dis[x + 1LL] = y + d;
        }
        if (x * 2LL <= 100000LL && dis[x * 2LL] > y + a) {
          q.push({y + a, x * 2LL});
          dis[x * 2LL] = y + a;
        }
        if (x * 3LL <= 100000LL && dis[x * 3LL] > y + b) {
          q.push({y + b, x * 3LL});
          dis[x * 3LL] = y + b;
        }
        if (x * 5LL <= 100000LL && dis[x * 5LL] > y + c) {
          q.push({y + c, x * 5LL});
          dis[x * 5LL] = y + c;
        }
      }
    }
    for (ll i = 1LL; i <= 100000LL; i++) {
      m.insert({i, dis[i]});
    }
    dfs(n, 0LL);
    cout << ans << endl;
  }
}