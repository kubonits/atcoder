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
string s;
int a = 0, b = 0, ans;

void dfs(int x, vector<int> v) {
  if (x == 4) {
    int f[10];
    for (int i = 0; i < 10; i++) {
      if (s[i] == 'o') {
        f[i] = 0;
      } else {
        f[i] = 1;
      }
    }
    for (int i = 0; i < 4; i++) {
      if (s[v[i]] == 'x') {
        return;
      }
      if (s[v[i]] == 'o') {
        f[v[i]] = 1;
        vector<int> u = {9, 9, 9, 9};
      }
    }
    for (int i = 0; i < 10; i++) {
      if (!f[i]) {
        return;
      }
    }
    ans++;
    return;
  }
  for (int i = 0; i < 10; i++) {
    v.push_back(i);
    dfs(x + 1, v);
    v.pop_back();
  }
}

int main() {
  cin >> s;
  vector<int> v;
  dfs(0, v);
  cout << ans << endl;
}
