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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n;
  string s;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  cin >> s;
  map<int, int> mr, ml;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R' && mr.find(y[i]) == mr.end()) {
      mr.insert({y[i], x[i]});
    } else if (s[i] == 'R') {
      mr[y[i]] = min(mr[y[i]], x[i]);
    }
    if (s[i] == 'L' && ml.find(y[i]) == ml.end()) {
      ml.insert({y[i], x[i]});
    } else if (s[i] == 'L') {
      ml[y[i]] = max(ml[y[i]], x[i]);
    }
    if (mr.find(y[i]) != mr.end() && ml.find(y[i]) != ml.end() &&
        mr[y[i]] < ml[y[i]]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
