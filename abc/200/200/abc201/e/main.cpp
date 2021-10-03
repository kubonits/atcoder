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

ll n;
vector<pair<int, ll> > g[200000];
ll d[200000];

void dfs(int x, int y, ll num) {
  d[x] = num;
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i].first != y) {
      dfs(g[x][i].first, x, num ^ g[x][i].second);
    }
  }
}

int main() {
  int v, u;
  ll w, ans = 0LL;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> v >> u >> w;
    v--;
    u--;
    g[v].push_back({u, w});
    g[u].push_back({v, w});
  }
  dfs(0, -1, 0);
  for (int i = 0; i < 60; i++) {
    ll cnt = 0LL;
    for (int j = 0; j < n; j++) {
      if (d[j] & (1LL << i)) {
        cnt++;
      }
    }
    ll x = cnt * (n - cnt) % MOD;
    x *= (1LL << i) % MOD;
    ans += x % MOD;
  }
  cout << ans % MOD << endl;
}
