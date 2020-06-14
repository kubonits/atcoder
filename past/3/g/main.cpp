#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int n, x, y, xx, yy;
  int dx[6] = {1, 0, -1, 1, -1, 0}, dy[6] = {1, 1, 1, 0, 0, -1};
  map<pair<int, int>, int> m;
  queue<pair<int, int> > q;
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    cin >> xx >> yy;
    m.insert({{xx, yy}, -1});
  }
  q.push({0, 0});
  m.insert({{0, 0}, 0});
  while (!q.empty()) {
    xx = q.front().first;
    yy = q.front().second;
    q.pop();
    if (x == xx && y == yy) {
      cout << m[{xx, yy}] << endl;
      return 0;
    }
    for (int i = 0; i < 6; i++) {
      if (m.find({xx + dx[i], yy + dy[i]}) == m.end()) {
        m.insert({{xx + dx[i], yy + dy[i]}, m[{xx, yy}] + 1});
        if (abs(xx + dx[i]) < 210 && abs(yy + dy[i]) < 210) {
          q.push({xx + dx[i], yy + dy[i]});
        }
      }
    }
  }
  cout << -1 << endl;
}