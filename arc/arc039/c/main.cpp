#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct dxy {
  int left;
  int right;
  int up;
  int down;
};

int main() {
  int k, x, y;
  string s;
  map<pair<int, int>, dxy> m;
  cin >> k >> s;
  x = y = 0;
  m.insert({{0, 0}, {-1, 1, 1, -1}});
  for (int i = 0; i < s.length(); i++) {
    int l, r, u, d;
    l = m[{x, y}].left;
    r = m[{x, y}].right;
    u = m[{x, y}].up;
    d = m[{x, y}].down;
    if (m.find({l, y}) == m.end()) {
      m.insert({{l, y}, {l - 1, r, y + 1, y - 1}});
    } else {
      m[{l, y}].right = m[{x, y}].right;
    }
    if (m.find({r, y}) == m.end()) {
      m.insert({{r, y}, {l, r + 1, y + 1, y - 1}});
    } else {
      m[{r, y}].left = m[{x, y}].left;
    }
    if (m.find({x, u}) == m.end()) {
      m.insert({{x, u}, {x - 1, x + 1, u + 1, d}});
    } else {
      m[{x, u}].down = m[{x, y}].down;
    }
    if (m.find({x, d}) == m.end()) {
      m.insert({{x, d}, {x - 1, x + 1, u, d - 1}});
    } else {
      m[{x, d}].up = m[{x, y}].up;
    }
    if (s[i] == 'L') {
      x = l;
    } else if (s[i] == 'R') {
      x = r;
    } else if (s[i] == 'U') {
      y = u;
    } else {
      y = d;
    }
  }
  cout << x << " " << y << endl;
}