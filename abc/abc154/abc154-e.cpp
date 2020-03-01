#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  char s[110];
  int k, n, ans = 0;
  scanf("%s", s);
  scanf("%d", &k);
  n = strlen(s);
  int dp0[110][5] = {}, dp1[110][5] = {};
  for (int i = 1; i <= 9; i++) {
    if (i < s[0] - '0') {
      dp0[1][1]++;
    } else if (i == s[0] - '0') {
      dp1[1][1]++;
    }
  }
  dp0[1][0] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 4; j++) {
      dp0[i][j] += dp0[i - 1][j];
      dp0[i][j + 1] += 9 * dp0[i - 1][j];
      if (s[i - 1] - '0') {
        dp0[i][j + 1] += (s[i - 1] - '0' - 1) * dp1[i - 1][j];
        dp1[i][j + 1] += dp1[i - 1][j];
        dp0[i][j] += dp1[i - 1][j];
      } else {
        dp1[i][j] += dp1[i - 1][j];
      }
    }
  }
  printf("%d\n", dp0[n][k] + dp1[n][k]);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      printf("%d,%d ", dp0[i][j], dp1[i][j]);
    }
    printf("\n");
  }
}