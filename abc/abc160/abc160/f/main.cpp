//解説AC
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll kai[200001], inv[200001];
int n, k;
ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n /= 2;
  }
  return res;
}
void init() {
  kai[0] = 1LL;
  for (ll i = 1LL; i <= 200000; i++) {
    kai[i] = kai[i - 1] * i;
    kai[i] %= MOD;
  }
  inv[200000] = mod_pow(kai[200000], MOD - 2LL, MOD);
  for (ll i = 199999; i >= 0; i--) {
    inv[i] = inv[i + 1] * (i + 1);
    inv[i] %= MOD;
  }
}

ll comb(ll r, ll c) {
  ll res;
  res = kai[r];
  res *= inv[c];
  res %= MOD;
  res *= inv[r - c];
  res %= MOD;
  return res;
}

pair<ll, ll> dp[200001];
ll ans[200001];
vector<int> g[200001];

void dfs(int x, int y) {
  ll size = 1LL;
  dp[x] = {1LL, 1LL};
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] != y) {
      dfs(g[x][i], x);
      dp[x].second += dp[g[x][i]].second;
      dp[x].first *= dp[g[x][i]].first;
      dp[x].first %= MOD;
      dp[x].first *= inv[dp[g[x][i]].second];
      dp[x].first %= MOD;
    }
  }
  dp[x].first *= kai[dp[x].second - 1];
  dp[x].first %= MOD;
}

void dfs2(int x, int y) {
  if (y != -1) {
    ans[x] = ans[y] * kai[n - dp[x].second - 1];
    ans[x] %= MOD;
    ans[x] *= kai[dp[x].second];
    ans[x] %= MOD;
    ans[x] *= inv[dp[x].second - 1];
    ans[x] %= MOD;
    ans[x] *= inv[n - dp[x].second];
    ans[x] %= MOD;
  }
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] != y) {
      dfs2(g[x][i], x);
    }
  }
}

int main() {
  int a, b;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  init();
  dfs(1, -1);
  ans[1] = dp[1].first;
  dfs2(1, -1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
}
