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

int n, m, a, b;
vector<pair<int, int> > e;
set<pair<int, int> > s;
vector<int> v, f;

int calc(int x) {
  if (x == n) {
    for (int i = 0; i < m; i++) {
      a = v[e[i].first];
      b = v[e[i].second];
      if (s.find({min(a, b), max(a, b)}) == s.end()) {
        return 0;
      }
    }
    return 1;
  }
  for (int i = 0; i < n; i++) {
    if (f[i] == 0) {
      f[i] = 1;
      v[x] = i;
      if (calc(x + 1)) {
        return 1;
      }
      f[i] = 0;
    }
  }
  return 0;
}
int main() {
  cin >> n >> m;
  v.resize(n);
  f.resize(n);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    e.push_back({a, b});
  }
  for (int j = 0; j < m; j++) {
    cin >> a >> b;
    a--;
    b--;
    s.insert({min(a, b), max(a, b)});
  }
  cout << (calc(0) ? "Yes" : "No") << endl;
}
