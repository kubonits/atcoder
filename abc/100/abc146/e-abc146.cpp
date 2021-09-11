#include <algorithm>
#include <cstdio>
#include <map>
typedef long long ll;
using namespace std;
int n, k, a[200000], sum[2000010];
long long ans = 0;
map<int, ll> m;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] %= k;
    sum[i + 1] = sum[i] + a[i];
    sum[i + 1] %= k;
  }
  m.insert({0, 1});
  for (int i = 1; i <= n; i++) {
    if (i >= k) {
      m[((sum[i - k] - i % k) + k) % k]--;
    }
    if (m.find((sum[i] - i % k + k) % k) == m.end()) {
      m.insert({(sum[i] - i % k + k) % k, 1});
    } else {
      ans += m[(sum[i] - i % k + k) % k];
      m[(sum[i] - i % k + k) % k]++;
    }
  }
  printf("%lld\n", ans);
}