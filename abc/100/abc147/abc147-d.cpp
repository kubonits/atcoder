#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n;
ll ans = 0, a[300000], b[60] = {};
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    for (int j = 0; j < 60; j++) {
      if (a[i] & (1LL << j)) {
        b[j]++;
      }
    }
  }
  for (int i = 0; i < 60; i++) {
    ll x = (1LL << i);
    x %= MOD;
    x *= b[i];
    x %= MOD;
    x *= ((ll)n - b[i]);
    x %= MOD;
    ans += x;
    ans %= MOD;
  }
  printf("%lld\n", ans);
}