#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  string s;
  cin >> s;
  vector<vector<ll> > dp(s.length() + 1, vector<ll>(9));
  dp[0][0] = 1;
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < 9; j++) {
      dp[i + 1][j] = dp[i][j];
    }
    if (s[i] == 'c') {
      dp[i + 1][1] += dp[i][0];
    }
    if (s[i] == 'h') {
      dp[i + 1][2] += dp[i][1];
    }
    if (s[i] == 'o') {
      dp[i + 1][3] += dp[i][2];
    }
    if (s[i] == 'k') {
      dp[i + 1][4] += dp[i][3];
    }
    if (s[i] == 'u') {
      dp[i + 1][5] += dp[i][4];
    }
    if (s[i] == 'd') {
      dp[i + 1][6] += dp[i][5];
    }
    if (s[i] == 'a') {
      dp[i + 1][7] += dp[i][6];
    }
    if (s[i] == 'i') {
      dp[i + 1][8] += dp[i][7];
    }
    for (int j = 0; j < 9; j++) {
      dp[i + 1][j] %= MOD;
    }
  }
  cout << dp[s.length()][8] << endl;
}