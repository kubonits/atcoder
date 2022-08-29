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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n, ans = 0;
  cin >> n;
  vector<int> m(n);
  vector<vector<int> > p(n), e(n);
  map<int, pair<int, int> > ma;
  for (int i = 0; i < n; i++) {
    cin >> m[i];
    p[i].resize(m[i]);
    e[i].resize(m[i]);
    for (int j = 0; j < m[i]; j++) {
      cin >> p[i][j] >> e[i][j];
      if (ma.find(p[i][j]) == ma.end()) {
        ma.insert({p[i][j], {e[i][j], 0}});
      } else if (ma[p[i][j]].first < e[i][j]) {
        ma[p[i][j]].second = ma[p[i][j]].first;
        ma[p[i][j]].first = e[i][j];
      } else if (ma[p[i][j]].second < e[i][j]) {
        ma[p[i][j]].second = e[i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int flag = 0;
    for (int j = 0; j < m[i]; j++) {
      if (e[i][j] > ma[p[i][j]].second) {
        flag = 1;
      }
    }
    ans += flag;
  }
  cout << (ans < n ? ans + 1 : ans) << endl;
}
