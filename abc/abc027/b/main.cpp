#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
typedef long long ll;
using namespace std;

pair<int, ll> g[18];

int dfs(int x) {
  if (g[x].first == x) {
    return x;
  }
  return g[x].first = dfs(g[x].first);
}

int main() {
  int n;
  string s, t;
  vector<int> v1[26], v2[26];
  ll ans = 1LL;
  cin >> n >> s >> t;
  for (int i = 0; i < n; i++) {
    if (s[i] >= '0' && s[i] <= '9' || t[i] >= '0' && t[i] <= '9') {
      g[i].second = 1LL;
    } else if (i == 0) {
      g[i].second = 9LL;
    } else {
      g[i].second = 10LL;
    }
    g[i].first = i;
    if (s[i] >= 'A' && s[i] <= 'Z') {
      v1[s[i] - 'A'].push_back(i);
    }
    if (t[i] >= 'A' && t[i] <= 'Z') {
      v1[t[i] - 'A'].push_back(i);
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int k = 0; k < v1[i].size(); k++) {
      for (int j = k + 1; j < v1[i].size(); j++) {
        int l = dfs(v1[i][k]);
        int r = dfs(v1[i][j]);
        if (l < r) {
          g[l].second = g[r].second = min(g[l].second, g[r].second);
          g[r].first = l;
        } else if (l > r) {
          g[l].second = g[r].second = min(g[l].second, g[r].second);
          g[l].first = g[r].first;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    dfs(i);
    if (g[i].first == i) {
      ans *= g[i].second;
    }
  }
  cout << ans << endl;
}