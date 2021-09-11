#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int n, dp[200010];
int main() {
  scanf("%d", &n);
  dp[0] = 0;
  for (int i = 0; i <= 9; i++) {
    dp[i] = i;
  }
  for (int i = 10; i <= 99; i++) {
    int x = i / 10, y = i % 10;
    dp[i] = dp[i - 1];
    if (y == 0)
      ;
    else if (x == y) {
      dp[i] += 3;
    } else if (x > y) {
      dp[i] += 2;
    }
  }
  for (int i = 100; i <= 999; i++) {
    int x = i / 100, y = i % 10;
    dp[i] = dp[i - 1];
    if (y == 0)
      ;
    else if (x == y) {
      dp[i] += 4;
      int z = i / 10 - 10 * x;
      dp[i] += 2 * z + 1;
    } else if (x > y) {
      dp[i] += 2;
      dp[i] += 20;
    } else if (x < y) {
      dp[i] += 2;
    }
  }
  for (int i = 1000; i <= 9999; i++) {
    int x = i / 1000, y = i % 10;
    dp[i] = dp[i - 1];
    if (y == 0)
      ;
    else if (x == y) {
      dp[i] += 24;
      int z = i / 10 - 100 * x;
      dp[i] += 2 * z + 1;
    } else if (x > y) {
      dp[i] += 22;
      dp[i] += 200;
    } else if (x < y) {
      dp[i] += 22;
    }
  }
  for (int i = 10000; i <= 99999; i++) {
    int x = i / 10000, y = i % 10;
    dp[i] = dp[i - 1];
    if (y == 0)
      ;
    else if (x == y) {
      dp[i] += 224;
      int z = i / 10 - 1000 * x;
      dp[i] += 2 * z + 1;
    } else if (x > y) {
      dp[i] += 2222;
    } else if (x < y) {
      dp[i] += 222;
    }
  }
  for (int i = 100000; i <= 200000; i++) {
    int x = i / 100000, y = i % 10;
    dp[i] = dp[i - 1];
    if (y == 0)
      ;
    else if (x == y) {
      dp[i] += 2224;
      int z = i / 10 - 10000 * x;
      dp[i] += 2 * z + 1;
    } else if (x > y) {
      dp[i] += 22222;
    } else if (x < y) {
      dp[i] += 2222;
    }
  }
  printf("%d\n", dp[n]);
}