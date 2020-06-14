#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[(1 << 15)];
int n, m, g[15][15], flag;
string s[15];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (s[i][k] != '*' && s[j][k] != '*' && s[i][k] != s[j][k]) {
          g[i][j] = g[j][i] = 1;
          break;
        }
      }
    }
  }
  for (int i = 1; i < (1 << n); i++) {
    dp[i] = 20;
    vector<int> v;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        v.push_back(j);
      }
    }
    flag = 1;
    for (int j = 0; j < v.size(); j++) {
      for (int k = j + 1; k < v.size(); k++) {
        if (g[v[j]][v[k]]) {
          flag = 0;
        }
      }
    }
    if (flag) {
      dp[i] = 1;
    } else {
      for (int j = 0; j < i; j++) {
        if (j == (i & j)) {
          dp[i] = min(dp[i], dp[j] + dp[(i ^ j)]);
        }
      }
    }
    if (dp[i] == 0) {
      cout << i << endl;
    }
  }
  cout << dp[(1 << n) - 1] << endl;
}