#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int dp[10001];

int main() {
  int m, n, a, b;
  queue<int> q;
  vector<pair<int, int> > v;
  scanf("%d%d", &m, &n);
  for (int i = 0; i <= m; i++) {
    scanf("%d%d", &a, &b);
    v.push_back({a, b});
  }
  for (int i = 1; i <= 10000; i++) {
    dp[i] = 10000000;
  }
  dp[0] = 0;
  dp[1] = 1;
  q.push(1);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < m; i++) {
      if (x >= v[i].first && x + v[i].second - v[i].first <= 10000 &&
          dp[x + v[i].second - v[i].first] > dp[x] + 1) {
        dp[x + v[i].second - v[i].first] = dp[x] + 1;
        q.push(x + v[i].second - v[i].first);
      }
    }
  }
  if (dp[n] == 10000000) {
    printf("-1\n");
  } else {
    printf("%d\n", dp[n]);
  }
}