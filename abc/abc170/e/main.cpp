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

int main() {
  int n, q, c, d;
  cin >> n >> q;
  vector<int> a(n + 10), b(n + 10);
  set<pair<int, int> > ans;
  vector<set<pair<int, int> > > s(200010);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    s[b[i]].insert({a[i], i});
  }
  for (int i = 0; i <= 200000; i++) {
    if (!s[i].empty()) {
      ans.insert(*s[i].rbegin());
    }
  }
  for (int i = 0; i < q; i++) {
    cin >> c >> d;
    pair<int, int> p = {a[c], c};
    s[b[c]].erase(p);
    if (ans.find(p) != ans.end()) {
      ans.erase(p);
      if (!s[b[c]].empty()) {
        ans.insert({s[b[c]].rbegin()->first, s[b[c]].rbegin()->second});
      }
    }
    b[c] = d;
    if (s[d].empty()) {
      ans.insert(p);
    } else if (*s[d].rbegin() < p) {
      ans.erase({s[d].rbegin()->first, s[d].rbegin()->second});
      ans.insert(p);
    }
    s[d].insert(p);
    cout << ans.begin()->first << endl;
  }
}