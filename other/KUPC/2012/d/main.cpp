#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
  int n, m, l, r;
  int dp[101];
  vector<pair<int, int> > v;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    dp[i] = 1000;
  }
  dp[0] = 0;
  for (int i = 0; i < m; i++) {
    cin >> l >> r;
    v.push_back({l, r});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < m; i++) {
    for (int j = v[i].first - 1; j < v[i].second; j++) {
      dp[v[i].second] = min(dp[v[i].second], dp[j] + 1);
    }
  }
  if (dp[n] == 1000) {
    cout << "Impossible" << endl;
  } else {
    cout << dp[n] << endl;
  }
}