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
int n, k;
vector<string> s;
set<vector<string> > ses;

int dfs(int x) {
  int res = 0;
  ses.insert(s);
  if (x == k) {
    return 1;
  }
  for (int i = 0; i < n * n; i++) {
    if (s[i / n][i % n] == '.') {
      int flag = 0;
      if (x == 0) {
        flag = 1;
      }
      if (i / n - 1 >= 0 && s[i / n - 1][i % n] == '@') {
        flag = 1;
      }
      if (i / n + 1 < n && s[i / n + 1][i % n] == '@') {
        flag = 1;
      }
      if (i % n - 1 >= 0 && s[i / n][i % n - 1] == '@') {
        flag = 1;
      }
      if (i % n + 1 < n && s[i / n][i % n + 1] == '@') {
        flag = 1;
      }
      if (flag) {
        s[i / n][i % n] = '@';
        if (ses.find(s) == ses.end()) {
          res += dfs(x + 1);
        }
        s[i / n][i % n] = '.';
      }
    }
  }
  return res;
}

int main() {
  cin >> n >> k;
  s.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  set<int> se;
  cout << dfs(0) << endl;
}