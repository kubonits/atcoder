#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

pair<int, int> dp[1000002];
int main() {
  int n, a, b, t, p = 0;
  vector<pair<pair<int, int>, int> > v, v2;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({{-b, a}, i});
    v2.push_back({{-b, a}, i + 1});
  }
  for (int i = 0; i <= 1000001; i++) {
    dp[i] = {0, -1000000};
  }
  sort(v.begin(), v.end());
  for (int i = -1000000; i <= 0; i++) {
    dp[-i] = max(dp[-i], dp[-i + 1]);
    while (p < n && v[p].first.first == i) {
      dp[v[p].first.second] =
          max(dp[v[p].first.second], {dp[-i].first + 1, -v[p].second});
      p++;
    }
  }
  t = 0;
  cout << dp[0].first << endl;
  while (dp[t].second != -1000000) {
    if (t != 0) {
      cout << " ";
    }
    cout << -dp[t].second + 1;
    t = -v2[-dp[t].second].first.first;
  }
  cout << endl;
}