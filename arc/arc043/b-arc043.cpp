#include <algorithm>
#include <cstdio>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> d(n), sum(100001), dp(100001);
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
  }
  for (int i = 1; i <= 100000; i++) {
    sum[i] = 1;
    dp[i] = 0;
  }
  sum[0] = 1;
  dp[0] = 0;
  sort(d.begin(), d.end());
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j <= 100000; j++) {
      dp[j] = 0;
    }
    for (int j = 0; j < n; j++) {
      dp[d[j]] += sum[d[j] / 2];
      dp[d[j]] %= MOD;
    }
    sum[0] = 0;
    for (int j = 1; j <= 100000; j++) {
      sum[j] = sum[j - 1] + dp[j];
      sum[j] %= MOD;
    }
  }
  printf("%d\n", sum[100000]);
}