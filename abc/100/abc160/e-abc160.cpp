#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;
int x, y, a, b, c;
ll p[100000], q[100000], r[100000], ans;
priority_queue<ll, vector<ll>, greater<ll>> que;
int main() {
  scanf("%d%d%d%d%d", &x, &y, &a, &b, &c);
  for (int i = 0; i < a; i++) {
    scanf("%lld", &p[i]);
  }
  for (int i = 0; i < b; i++) {
    scanf("%lld", &q[i]);
  }
  for (int i = 0; i < c; i++) {
    scanf("%lld", &r[i]);
  }
  sort(p, p + a);
  sort(q, q + b);
  sort(r, r + c);
  for (int i = 0; i < x; i++) {
    ans += p[a - 1 - i];
    que.push(p[a - 1 - i]);
  }
  for (int i = 0; i < y; i++) {
    ans += q[b - 1 - i];
    que.push(q[b - 1 - i]);
  }
  for (int i = 0; i < c; i++) {
    if (que.top() < r[c - 1 - i]) {
      ans -= que.top();
      ans += r[c - 1 - i];
      que.pop();
      que.push(r[c - 1 - i]);
    }
  }
  printf("%lld\n", ans);
}