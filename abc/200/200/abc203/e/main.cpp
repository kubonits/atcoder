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

int main() {
  int n, m, x, y;
  cin >> n >> m;
  vector<pair<int, int> > v;
  map<int, vector<int> > ma;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    ma[x].push_back(y);
  }
  sort(v.begin(), v.end());
  set<int> s, sadd, sera;
  s.insert(n);
  for (auto &&x : ma) {
    sadd.clear();
    sera.clear();
    for (int i = 0; i < x.second.size(); i++) {
      sera.insert(x.second[i]);
      if (s.find(x.second[i] + 1) != s.end() ||
          s.find(x.second[i] - 1) != s.end()) {
        sadd.insert(x.second[i]);
      }
    }
    for (auto &&y : sera) {
      s.erase(y);
    }
    for (auto &&y : sadd) {
      s.insert(y);
    }
  }
  cout << s.size() << endl;
}