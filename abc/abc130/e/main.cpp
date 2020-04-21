#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll dp1[2001][2001], dp2[2001][2001], sum[2001][2001];
int main() {
  int n, m, s[2000], t[2000];
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }
  dp1[0][0] = dp2[0][0] = sum[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    dp1[i][0] = 0;
    dp2[i][0] = 1;
    sum[i][0] = 0;
  }
  for (int i = 1; i <= m; i++) {
    dp1[0][i] = 0;
    dp2[0][i] = 1;
    sum[0][i] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i] == t[j]) {
        dp1[i + 1][j + 1] = dp2[i][j];
      }
      sum[i + 1][j + 1] = sum[i + 1][j] + dp1[i + 1][j + 1];
      sum[i + 1][j + 1] %= MOD;
      dp2[i + 1][j + 1] = dp2[i][j + 1] + sum[i + 1][j + 1];
      dp2[i + 1][j + 1] %= MOD;
    }
  }
  cout << dp2[n][m] << endl;
}