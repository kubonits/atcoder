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
  int h, w, m, x, y, ans = 0, maxh = 0, maxw = 0;
  set<pair<int, int> > s;
  set<int> sh;
  cin >> h >> w >> m;
  vector<int> sumh(h), sumw(w);
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    x--;
    y--;
    sumh[x]++;
    sumw[y]++;
    maxh = max(maxh, sumh[x]);
    maxw = max(maxw, sumw[y]);
    s.insert({x, y});
  }
  for (int i = 0; i < h; i++) {
    if (sumh[i] == maxh) {
      sh.insert(i);
    }
  }
  for (int i = 0; i < w; i++) {
    if (sumw[i] == maxw) {
      for (auto&& xx : sh) {
        if (s.find({xx, i}) == s.end()) {
          cout << maxh + maxw << endl;
          return 0;
        }
      }
    }
  }
  cout << maxh + maxw - 1 << endl;
}