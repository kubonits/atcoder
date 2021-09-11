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

map<int, pair<int, int> > m;

int ldfs(int x) {
  if (m[x].first == x) {
    return x;
  }
  return m[x].first = ldfs(m[x].first);
}

int rdfs(int x) {
  if (m[x].second == x) {
    return x;
  }
  return m[x].second = rdfs(m[x].second);
}

int main() {
  int n, t, l, r;
  vector<pair<int, int> > v;

  set<int> s;
  cin >> t;
  while (t--) {
    cin >> n;
    int flag = 1;
    v.clear();
    s.clear();
    m.clear();
    for (int i = 0; i < n; i++) {
      cin >> l >> r;
      v.push_back({r, l});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      int x = v[i].second;
      int y = v[i].first;
      if (s.find(x) == s.end()) {
        s.insert(x);
        m[x] = {x, x};
        if (s.find(x - 1) != s.end()) {
          int left = ldfs(x - 1);
          m[x].first = left;
          m[x - 1].second = m[x].second;
        }
        if (s.find(x + 1) != s.end()) {
          int right = rdfs(x + 1);
          m[x + 1].first = m[x].first;
          m[x].second = right;
        }
      } else if (rdfs(x) < y) {
        x = m[x].second + 1;
        s.insert(x);
        m[x] = {x, x};
        int left = ldfs(x - 1);
        m[x].first = left;
        m[x - 1].second = m[x].second;
        if (s.find(x + 1) != s.end()) {
          int right = rdfs(x + 1);
          m[x + 1].first = m[x].first;
          m[x].second = right;
        }
      } else {
        flag = 0;
        break;
      }
    }
    cout << (flag ? "Yes" : "No") << endl;
  }
}