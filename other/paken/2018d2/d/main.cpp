#include <algorithm>
#include <cmath>
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
int n, m, q, x, y, z, l, r, p;
string s, d[150000], f[150000];
set<int> b, w;
vector<string> ans;
vector<pair<pair<int, int>, int> > v;
int main() {
  cin >> n >> s >> m;
  for (int i = 0; i < m; i++) {
    cin >> d[i] >> f[i];
  }
  cin >> q;
  ans.resize(q);
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    v.push_back({{x, y - 1}, i});
  }
  sort(v.begin(), v.end());
  if (s[0] == 'B') {
    b.insert(0);
  } else {
    w.insert(0);
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == 'B' && s[i - 1] == 'W') {
      b.insert(i);
    } else if (s[i] == 'W' && s[i - 1] == 'B') {
      w.insert(i);
    }
  }
  p = 0;
  l = 0;
  r = n - 1;
  for (int i = 0; i < q; i++) {
    while (p < m && p < v[i].first.first) {
      if (d[p] == "L") {
        l--;
        if (f[p] == "B") {
          if (w.empty() || *b.begin() < *w.begin()) {
            b.erase(b.begin());
          } else if (!b.empty() && *w.begin() < *b.begin()) {
            b.erase(b.begin());
            w.erase(w.begin());
          }
          b.insert(l);
        } else {
          if (b.empty() || *w.begin() < *b.begin()) {
            w.erase(w.begin());
          } else if (!w.empty() && *b.begin() < *w.begin()) {
            b.erase(b.begin());
            w.erase(w.begin());
          }
          w.insert(l);
        }
      } else {
        r++;
        if (f[p] == "B") {
          if (b.empty()) {
            b.insert(r);
          } else if (!w.empty() && *b.rbegin() < *w.rbegin()) {
            w.erase(*w.rbegin());
          }
        } else {
          if (w.empty()) {
            w.insert(r);
          } else if (!b.empty() && *b.rbegin() > *w.rbegin()) {
            b.erase(*b.rbegin());
          }
        }
      }
      p++;
    }
    z = v[i].first.second + l;
    if (b.empty()) {
      ans[v[i].second] = "W";
    } else if (w.empty()) {
      ans[v[i].second] = "B";
    } else {
      if (b.upper_bound(z) != b.end()) {
        x = *b.upper_bound(z);
      } else {
        x = *b.rbegin();
      }
      if (w.upper_bound(z) != w.end()) {
        y = *w.upper_bound(z);
      } else {
        y = *w.rbegin();
      }
      if (x > z && y > z && x > y || x <= z && y > z ||
          x <= z && y <= z && x > y) {
        ans[v[i].second] = "B";
      } else {
        ans[v[i].second] = "W";
      }
    }
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;
  }
}