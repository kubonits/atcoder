// 解説AC
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[(1 << 15)], f[15][2400], g[15][15];

int main() {
  vector<int> v;
  int n, a, b;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    a = 100 * stoi(s.substr(0, 2)) + stoi(s.substr(3));
    cin >> s;
    b = 100 * stoi(s.substr(0, 2)) + stoi(s.substr(3));
    for (int j = a; j < b; j++) {
      f[i][j % 2400] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = 0; k < 2400; k++) {
        if (f[i][k] + f[j][k] == 2) {
          g[i][j] = g[j][i] = 1;
          break;
        }
      }
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    v.clear();
    dp[i] = 100;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        v.push_back(j);
      }
    }
    int flag = 1;
    for (int j = 0; j < v.size(); j++) {
      for (int k = j + 1; k < v.size(); k++) {
        if (g[v[j]][v[k]] == 1) {
          flag = 0;
          break;
        }
      }
    }
    if (flag) {
      dp[i] = 1;
    } else {
      for (int j = 0; j < i; j++) {
        if ((i ^ j) == i - j) {
          dp[i] = min(dp[i], dp[j] + dp[i ^ j]);
        }
      }
    }
  }
  cout << dp[(1 << n) - 1] << endl;
}