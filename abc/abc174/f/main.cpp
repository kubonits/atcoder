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
int bit[500001], n;

int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= (i & -i);
  }
  return s;
}

void add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += (i & -i);
  }
}
int main() {
  int q, a, l, r;

  vector<pair<pair<int, int>, int> > v;
  cin >> n >> q;
  vector<set<int> > s(n + 1);
  vector<int> ans(q);
  for (int i = 0; i < n; i++) {
    cin >> a;
    s[a].insert(i + 1);
  }
  for (int i = 0; i <= n; i++) {
    set<int>::iterator it = s[i].begin();
    for (; it != s[i].end(); it++) {
      set<int>::iterator it2 = it;
      it2++;
      if (it2 != s[i].end()) {
        v.push_back({{*it2, -1}, *it});
      }
    }
  }
  for (int i = 0; i < q; i++) {
    cin >> l >> r;
    v.push_back({{r, i}, l});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    if (v[i].first.second == -1) {
      add(v[i].second, 1);
    } else {
      ans[v[i].first.second] = v[i].first.first - v[i].second + 1 -
                               sum(v[i].first.first) + sum(v[i].second - 1);
    }
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;
  }
}
