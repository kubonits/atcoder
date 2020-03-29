#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
  int n, m, x[100000], cnt[100000] = {};
  vector<vector<int> > v;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  sort(x, x + n);
  for (int i = 0; i < n - 1; i++) {
    if (x[i] == x[i + 1]) {
      cnt[x[i] % m]++;
      i++;
    }
  }
  v.resize(m);
  for (int i = 0; i < n; i++) {
    v[x[i] % m].push_back(x[i]);
  }
  int ans = 0;
  for (int i = 0; i <= m / 2; i++) {
    if (i == 0 || m - i == i) {
      ans += v[i].size() / 2;
    } else {
      ans += min(v[i].size(), v[m - i].size());
      int a;
      if (v[i].size() > v[m - i].size()) {
        a = i;
      } else {
        a = m - i;
      }
      ans += min((int)((v[a].size() - v[m - a].size()) / 2), cnt[a]);
    }
  }
  printf("%d\n", ans);
}