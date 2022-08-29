#include <iostream>
#include <set>
#include <string>

using namespace std;

int sum[100001][26];
int main() {
  string s, t[26];
  set<string> se;
  int n, k;
  cin >> n >> k >> s;
  for (int i = 0; i < 26; i++) {
    t[i].resize(1);
    t[i][0] = 'a' + i;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      sum[i + 1][j] = sum[i][j];
      if (s[i] == 'a' + j) {
        sum[i + 1][j]++;
      }
    }
  }
  for (int i = k; k + i <= n; i++) {
    string u = "";
    for (int j = 0; j < 26; j++) {
      if (sum[i][j] - sum[i - k][j]) {
        u += t[j] + to_string(sum[i][j] - sum[i - k][j]);
      }
    }
    se.insert(u);
    u = "";
    for (int j = 0; j < 26; j++) {
      if (sum[i + k][j] - sum[i][j]) {
        u += t[j] + to_string(sum[i + k][j] - sum[i][j]);
      }
    }
    if (se.find(u) != se.end()) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}