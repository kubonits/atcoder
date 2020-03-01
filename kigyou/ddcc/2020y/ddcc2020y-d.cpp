#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
int m;
ll c[200000], d[200000], num[10] = {}, ans = 0, a;
int main() {
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%lld%lld", &d[i], &c[i]);
    num[d[i]] += c[i];
    ans += c[i];
  }
  for (ll i = 1; i <= 9; i++) {
    while (num[i] >= 10) {
      ans += num[i] / 10 * i;
      num[i] = num[i] / 10 + num[i] % 10;
    }
  }
  a = 0;
  for (int i = 1; i <= 9; i++) {
    while (num[i]) {
      num[i]--;
      a += i;
      if (a >= 10) {
        ans++;
        a %= 10;
        a++;
        if (a == 10) {
          ans++;
          a = 1;
        }
      }
    }
  }
  printf("%lld\n", ans - 1);
}