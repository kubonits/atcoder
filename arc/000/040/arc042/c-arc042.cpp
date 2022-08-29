#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int dp[5110];

int main() {
  int n, p, a, b, ans = 0;
  vector<pair<int, int> > v;
  scanf("%d%d", &n, &p);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());
  for (int i = v.size() - 1; i >= 0; i--) {
    for (int j = p + v[i].first; j - v[i].first >= 0; j--) {
      dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
    }
    ans = max(ans, dp[p + v[i].first]);
  }
  printf("%d\n", ans);
}