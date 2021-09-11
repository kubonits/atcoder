#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

map<pair<int, int>, int> ma;

int dfs(int x, int y) {
  int res = 0;
  if (x > y || y == 0) {
    return 0;
  }
  if (ma.find({x, y}) != ma.end()) {
    return ma[{x, y}];
  }
  res = 1 + dfs(x + 1, y - x);
  res = max(res, dfs(x + 1, y));
  ma.insert({{x, y}, res});
  return res;
}

int main() {
  ll n;
  int ans = 0;
  vector<int> v;
  cin >> n;
  ll nn = n;
  ll cnt;
  for (ll i = 2; i <= 1000000; i++) {
    cnt = 0;
    while (nn % i == 0) {
      cnt++;
      nn /= i;
    }
    if (cnt) {
      v.push_back(cnt);
    }
  }
  if (nn != 1LL) {
    v.push_back(1);
  }
  for (int i = 0; i < v.size(); i++) {
    ans += dfs(1, v[i]);
  }
  cout << ans << endl;
}