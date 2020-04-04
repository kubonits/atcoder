#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std;
typedef long long ll;
ll dpv[200001], dpw[200010];
int n, w;
ll b, maxw = 0, maxv = 0, a;
pair<ll, ll> p[200];
ll sum[210];
ll ans = 0;
ll dfs(int x, ll y, ll z) {
  if (x == n) {
    ans = max(z, ans);
    return z;
  }
  ll res = 0LL;
  if (y + p[x].second <= w && ans < z + sum[n] - sum[x]) {
    res = dfs(x + 1, y + p[x].second, z + p[x].first);
  }
  if (ans < z + sum[n] - sum[x]) {
    res = max(res, dfs(x + 1, y, z));
  }
  ans = max(ans, res);
  return res;
}

int main() {
  scanf("%d%d", &n, &w);
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &a, &b);
    p[i] = {a, b};
    maxv = max(maxv, a);
    maxw = max(maxw, b);
    sum[i + 1] = sum[i] + a;
  }
  if (n <= 30) {
    printf("%lld\n", dfs(0LL, 0LL, 0LL));
    return 0;
  } else if (maxw <= 1000) {
    for (int i = 0; i < n; i++) {
      for (int j = 200000; j - p[i].second >= 0; j--) {
        dpw[j] = max(dpw[j], dpw[j - p[i].second] + p[i].first);
      }
    }
    printf("%lld\n", dpw[min(w, 200000)]);
    return 0;
  } else {
    for (int i = 0; i <= 200000; i++) {
      dpv[i] = 2000000000;
    }
    dpv[0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 200000; j - p[i].first >= 0; j--) {
        dpv[j] = min(dpv[j], dpv[j - p[i].first] + p[i].second);
      }
    }
    for (int i = 0; i <= 200000; i++) {
      if (dpv[i] <= w) {
        ans = i;
      }
    }
    printf("%lld\n", ans);
  }
}