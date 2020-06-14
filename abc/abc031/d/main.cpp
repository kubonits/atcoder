#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, k, a[9];
vector<int> v[50];
string w[50];

int dfs(int x) {
  int sum = 0, p;
  string s[9];
  int f[9] = {};
  if (x == k) {
    for (int i = 0; i < n; i++) {
      sum = 0;
      for (int j = 0; j < v[i].size(); j++) {
        sum += a[v[i][j]];
      }
      if (sum != w[i].length()) {
        return 0;
      }
    }
    for (int i = 0; i < n; i++) {
      p = 0;
      for (int j = 0; j < v[i].size(); j++) {
        if (f[v[i][j]] == 0) {
          s[v[i][j]] = w[i].substr(p, a[v[i][j]]);
          f[v[i][j]] = 1;
        } else if (s[v[i][j]] != w[i].substr(p, a[v[i][j]])) {
          return 0;
        }
        p += a[v[i][j]];
      }
    }
    for (int i = 0; i < k; i++) {
      cout << s[i] << endl;
    }
    return 1;
  }
  for (int i = 1; i <= 3; i++) {
    a[x] = i;
    if (dfs(x + 1) == 1) {
      return 1;
    }
  }
  return 0;
}

int main() {
  string s;
  cin >> k >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> w[i];
    for (int j = 0; j < s.length(); j++) {
      v[i].push_back(s[j] - '1');
    }
  }
  dfs(0);
}