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

vector<ll> f, k;
vector<vector<ll> > a;
void dfs(int x) {
  if (f[x]) {
    return;
  }
  f[x] = 1;
  for (int i = 0; i < a[x].size(); i++) {
    dfs(a[x][i]);
  }
}

int main() {
  ll n, t, ans = 0;
  cin >> n;
  f.resize(n + 1);
  k.resize(n + 1);
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> k[i] >> t;
    a[i].resize(t);
    for (int j = 0; j < t; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  dfs(n - 1);
  for (int i = 0; i < n; i++) {
    if (f[i]) {
      ans += k[i];
    }
  }
  cout << ans << endl;
}
