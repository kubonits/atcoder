#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n, m;

struct unionfind {
  int parent;
  int node;
  int edge;
};
unionfind g[100001];

void init() {
  for (int i = 0; i <= n; i++) {
    g[i].parent = i;
    g[i].node = 1;
    g[i].edge = 0;
  }
}

int find(int x) {
  if (x == g[x].parent) {
    return x;
  }
  int res = find(g[x].parent);
  g[x].node = g[res].node;
  g[x].edge = g[res].edge;
  g[x].parent = res;
  return res;
}

void merge(int x, int y) {
  if (x > y) {
    x ^= y;
    y ^= x;
    x ^= y;
  }
  g[x].node += g[y].node;
  g[x].edge += g[y].edge + 1;
  g[y].parent = x;
}

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

ll dp[5001][5001];

int main() {
  int p[5001];
  ll cnt = 0LL, ans, k = 0LL, mi = 0LL, m;
  vector<ll> v;
  cin >> n;
  m = n;
  init();
  for (int i = 0; i < n; i++) {
    cin >> p[i + 1];
    if (p[i + 1] == -1) {
      k++;
    } else {
      find(i + 1);
      find(p[i + 1]);
      if (g[i + 1].parent != g[p[i + 1]].parent) {
        merge(g[i + 1].parent, g[p[i + 1]].parent);
        cnt++;
      }
    }
  }
  ans = (cnt)*mod_pow((ll)n - 1, k, MOD) % MOD;
  for (int i = 1; i <= n; i++) {
    find(i);
    if (p[i] == -1) {
      v.push_back(g[i].node);
      m -= g[i].node;
    }
  }
  dp[0][0] = 1;
  for (ll i = 0; i < v.size(); i++) {
    ans += (n - v[i]) * mod_pow(n - 1, v.size() - 1, MOD) % MOD;
    ans %= MOD;
    for (ll j = 0; j <= i + 1; j++) {
      dp[i + 1][j] = dp[i][j];
      if (j == 1) {
        dp[i + 1][j] += dp[i][j - 1] * v[i] % MOD;
      } else if (j) {
        dp[i + 1][j] += dp[i][j - 1] * (ll)(j - 1) * v[i] % MOD;
      }
      dp[i + 1][j] %= MOD;
    }
  }
  for (ll i = 2; i <= n; i++) {
    ans +=
        MOD - dp[v.size()][i] % MOD * mod_pow(n - 1, v.size() - i, MOD) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}