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
#define INF 1000000000
int main() {
  int n, ans = INF;
  cin >> n;
  vector<int> x(n), y(n);
  vector<string> s(n);
  map<int, set<int> > udu, udd, lrl, lrr, uru, urr, ulu, ull, drd, drr, dld,
      dll;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> s[i];
    if (s[i] == "U") {
      udu[x[i]].insert(y[i]);
      uru[y[i] + x[i]].insert(x[i]);
      ulu[y[i] - x[i]].insert(x[i]);
    } else if (s[i] == "D") {
      udd[x[i]].insert(y[i]);
      drd[y[i] - x[i]].insert(y[i]);
      dld[y[i] + x[i]].insert(y[i]);
    } else if (s[i] == "R") {
      lrr[y[i]].insert(x[i]);
      urr[y[i] + x[i]].insert(y[i]);
      drr[y[i] - x[i]].insert(x[i]);
    } else {
      lrl[y[i]].insert(x[i]);
      ull[y[i] - x[i]].insert(y[i]);
      dll[y[i] + x[i]].insert(x[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == "U") {
      if (udd[x[i]].lower_bound(y[i]) != udd[x[i]].end()) {
        ans = min(ans, (*udd[x[i]].lower_bound(y[i]) - y[i]) * 5);
      }
      if (urr[y[i] + x[i]].lower_bound(y[i]) != urr[y[i] + x[i]].end()) {
        ans = min(ans, (*urr[y[i] + x[i]].lower_bound(y[i]) - y[i]) * 10);
      }
      if (ull[y[i] - x[i]].lower_bound(y[i]) != ull[y[i] - x[i]].end()) {
        ans = min(ans, (*ull[y[i] - x[i]].lower_bound(y[i]) - y[i]) * 10);
      }
    } else if (s[i] == "D") {
      if (dll[y[i] + x[i]].lower_bound(x[i]) != dll[y[i] + x[i]].end()) {
        ans = min(ans, (*dll[y[i] + x[i]].lower_bound(x[i]) - x[i]) * 10);
      }
    } else if (s[i] == "R") {
      if (lrl[y[i]].lower_bound(x[i]) != lrl[y[i]].end()) {
        ans = min(ans, (*lrl[y[i]].lower_bound(x[i]) - x[i]) * 5);
      }
      if (drd[y[i] - x[i]].lower_bound(y[i]) != drd[y[i] - x[i]].end()) {
        ans = min(ans, (*drd[y[i] - x[i]].lower_bound(y[i]) - y[i]) * 10);
      }
    }
  }
  if (ans == INF) {
    cout << "SAFE" << endl;
  } else {
    cout << ans << endl;
  }
}