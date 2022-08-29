#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
int sum[100001];
vector<pair<int, int> > v[100001];

void dfs(int x, int y, int z) {
  sum[x] = z;
  for (int i = 0; i < v[x].size(); i++) {
    if (v[x][i].first != y) {
      dfs(v[x][i].first, x, z ^ v[x][i].second);
    }
  }
}

int main() {
  int a, b, c, x, n;
  map<int, ll> m;
  ll ans = 0LL;
  cin >> n >> x;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  dfs(1, -1, 0);
  for (int i = 1; i <= n; i++) {
    if (m.find(sum[i]) == m.end()) {
      m.insert({sum[i], 1LL});
    } else {
      m[sum[i]]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (x == 0) {
      ans += m[sum[i]] - 1LL;
    } else if (m.find(sum[i] ^ x) != m.end()) {
      ans += m[sum[i] ^ x];
    }
  }
  cout << ans / 2LL << endl;
}