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

int calc(pair<int, int> x, pair<int, int> y) {
  return max(max(x.first, y.first) - min(x.first, y.first),
             max(x.second, y.second) - min(x.second, y.second));
}

int main() {
  int n, xx, yy;
  cin >> n;
  vector<pair<int, int> > x(n), y(n), p(n);
  set<pair<int, int> > s;
  priority_queue<int> q;
  for (int i = 0; i < n; i++) {
    cin >> xx >> yy;
    x[i] = {xx, i};
    y[i] = {yy, i};
    p[i] = {xx, yy};
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  q.push(calc(p[x[0].second], p[x[n - 1].second]));
  s.insert(
      {min(x[0].second, x[n - 1].second), max(x[0].second, x[n - 1].second)});
  if (s.find({min(x[1].second, x[n - 1].second),
              max(x[1].second, x[n - 1].second)}) == s.end()) {
    q.push(calc(p[x[1].second], p[x[n - 1].second]));
    s.insert(
        {min(x[1].second, x[n - 1].second), max(x[0].second, x[n - 1].second)});
  }
  if (s.find({min(x[0].second, x[n - 2].second),
              max(x[0].second, x[n - 2].second)}) == s.end()) {
    q.push(calc(p[x[0].second], p[x[n - 2].second]));
    s.insert(
        {min(x[0].second, x[n - 2].second), max(x[0].second, x[n - 2].second)});
  }
  if (s.find({min(y[0].second, y[n - 1].second),
              max(y[0].second, y[n - 1].second)}) == s.end()) {
    q.push(calc(p[y[0].second], p[y[n - 1].second]));
    s.insert(
        {min(y[0].second, y[n - 1].second), max(y[0].second, y[n - 1].second)});
  }
  if (s.find({min(y[1].second, y[n - 1].second),
              max(y[1].second, y[n - 1].second)}) == s.end()) {
    q.push(calc(p[y[1].second], p[y[n - 1].second]));
    s.insert(
        {min(y[1].second, y[n - 1].second), max(y[0].second, y[n - 1].second)});
  }
  if (s.find({min(y[0].second, y[n - 2].second),
              max(y[0].second, y[n - 2].second)}) == s.end()) {
    q.push(calc(p[y[0].second], p[y[n - 2].second]));
    s.insert(
        {min(y[0].second, y[n - 2].second), max(y[0].second, y[n - 2].second)});
  }
  q.pop();
  cout << q.top() << endl;
}
