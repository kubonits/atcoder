#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> v[11];

void dfs(string s) {
  if (s[0] != '0') {
    v[s.length()].push_back(s);
  }
  if (s.length() == 10) {
    return;
  }
  for (int i = 0; i <= 9; i++) {
    if (s[0] - '0' - i >= -1 && s[0] - '0' - i <= 1) {
      char c = ('0' + i);
      dfs(c + s);
    }
  }
}

int main() {
  int k;
  scanf("%d", &k);
  dfs("1");
  dfs("2");
  dfs("3");
  dfs("4");
  dfs("5");
  dfs("6");
  dfs("7");
  dfs("8");
  dfs("9");
  dfs("0");
  for (int i = 1; i <= 10; i++) {
    sort(v[i].begin(), v[i].end());
  }
  for (int i = 1; i <= 10; i++) {
    if (k <= v[i].size()) {
      cout << v[i][k - 1] << endl;
      return 0;
    } else {
      k -= v[i].size();
    }
  }
  for (int i = 0; i < v[2].size(); i++) {
    cout << v[2][i] << endl;
  }
}