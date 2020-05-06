#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, t, a, b, dp[6000] = {}, ans = 0;
  vector<pair<int, int> > p;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    p.push_back({a, -b});
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < n; i++) {
    for (int j = t - 1; j >= 0; j--) {
      dp[j + p[i].first] = max(dp[j + p[i].first], dp[j] - p[i].second);
    }
  }
  for (int i = 0; i < 6000; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}