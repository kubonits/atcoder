#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
ll a[200000], sum[200001] = {}, ans = 5000000000000000;
int main() {
  int n;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    sum[i + 1] = sum[i] + a[i];
  }
  for (int i = 0; i < n; i++) {
    ans = min(ans, max(sum[n] - sum[i], sum[i]) - min(sum[n] - sum[i], sum[i]));
  }
  printf("%lld\n", ans);
}
