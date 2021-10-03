#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  ll n, d, a, x, h, p = 0LL, ans = 0LL;
  vector<pair<ll, ll> > v;
  scanf("%lld%lld%lld", &n, &d, &a);
  vector<ll> sum(n + 2);
  sum[0] = 0;
  for (ll i = 0; i < n; i++) {
    scanf("%lld%lld", &x, &h);
    v.push_back({x, h});
    sum[i + 1] = 0LL;
  }
  sort(v.begin(), v.end());
  for (ll i = 0; i < n; i++) {
    sum[i + 1] += sum[i];
    if (sum[i + 1] < (v[i].second + a - 1) / a) {
      while (p < n && v[p].first <= v[i].first + 2 * d) {
        p++;
      }
      sum[p + 1] -= ((v[i].second + a - 1) / a - sum[i + 1]);
      ans += ((v[i].second + a - 1) / a - sum[i + 1]);
      sum[i + 1] += ((v[i].second + a - 1) / a - sum[i + 1]);
    }
  }
  printf("%lld\n", ans);
}