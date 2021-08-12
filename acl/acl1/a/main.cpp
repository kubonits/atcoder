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
int n, m;

struct unionfind {
  int parent;
  int node;
  int edge;
};
unionfind g[200001];

void init() {
  for (int i = 0; i <= n; i++) {
    g[i].parent = i;
    g[i].node = 1;
    g[i].edge = 0;
  }
}

int ufind(int x) {
  if (x == g[x].parent) {
    return x;
  }
  int res = ufind(g[x].parent);
  g[x].node = g[res].node;
  g[x].edge = g[res].edge;
  g[x].parent = res;
  return res;
}

void umerge(int x, int y) {
  g[x].node += g[y].node;
  g[x].edge += g[y].edge + 1;
  g[y].parent = x;
}

int main() {
  int x, y, flag;
  cin >> n;
  vector<int> ans(n + 1), dp(n + 5);
  set<pair<int, int>> s;
  vector<pair<pair<int, int>, int>> v;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back({{x, y}, i});
  }
  sort(v.begin(), v.end());
  init();
  s.insert({v[0].first.second, v[0].second});
  for (int i = 1; i < n; i++) {
    y = min(v[i].first.second, s.begin()->first);
    while (!s.empty() && s.begin()->first < v[i].first.second) {
      umerge(v[i].second, s.begin()->second);
      s.erase(s.begin());
    }
    s.insert({y, v[i].second});
  }
  for (int i = 0; i < n; i++) {
    x = ufind(i);
    cout << g[x].node << endl;
  }
}