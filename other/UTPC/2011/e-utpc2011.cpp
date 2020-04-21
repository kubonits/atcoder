#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
int main() {
  int n, a, b, ans = 0;
  vector<pair<int, int> > v;
  int dp[1000001] = {};
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    v.push_back({b, a});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    for (int j = v[i].first; j - v[i].second >= 0; j--) {
      dp[j] = max(dp[j], dp[j - v[i].second] + 1);
    }
  }
  for (int i = 0; i <= v[n - 1].first; i++) {
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
}