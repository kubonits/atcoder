#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<map<int, int> > u, d, l, r;
  int k, x, y, p, mini[2], maxi[2];
  string s;
  cin >> k >> s;
  u.resize(2 * k + 1);
  d.resize(2 * k + 1);
  l.resize(2 * k + 1);
  r.resize(2 * k + 1);
  x = y = 0;
  for (int i = 0; i < k; i++) {
    if (s[i] == 'U') {
      y++;
      mini[0] = mini[1] = y - 1;
      maxi[0] = maxi[1] = y;
      do {
        mini[1] = mini[0];
        maxi[1] = maxi[0];
        do {
          mini[1] = mini[0];
          maxi[1] = maxi[0];
          map<int, int>::iterator it = d[x + k].lower_bound(y);
          if (it != d[x + k].end() && it->second <= y) {
            y = it->first + 1;
            maxi[0] = max(maxi[0], it->first + 1);
            mini[0] = min(mini[0], it->second);
            u[y + k].erase(it->second);
            d[y + k].erase(it->first);
          }
        } while (mini[0] != mini[1] || maxi[0] != maxi[1]);
        map<int, int>::iterator it = l[y + k].lower_bound(x);
        if (it != l[y + k].end() && it->second <= x) {
          y++;
          mini[0] = y;
        }
      } while (mini[0] != mini[1] || maxi[0] != maxi[1]);
      u[x + k].insert({mini[0], maxi[0]});
      d[x + k].insert({maxi[0], mini[0]});
      l[y + k].insert({x, x});
      r[y + k].insert({x, x});
    }
    if (s[i] == 'D') {
      y--;
      mini[0] = mini[1] = y;
      maxi[0] = maxi[1] = y + 1;
      do {
        mini[1] = mini[0];
        maxi[1] = maxi[0];
        do {
          mini[1] = mini[0];
          maxi[1] = maxi[0];
          map<int, int>::iterator it = d[x + k].lower_bound(y);
          if (it != d[x + k].end() && it->second <= y) {
            y = it->second - 1;
            maxi[0] = max(maxi[0], it->first);
            mini[0] = min(mini[0], it->second - 1);
            u[y + k].erase(it->second);
            d[y + k].erase(it->first);
          }
        } while (mini[0] != mini[1] || maxi[0] != maxi[1]);
        map<int, int>::iterator it = l[y + k].lower_bound(x);
        if (it != l[y + k].end() && it->second <= x) {
          y--;
          mini[0] = y;
        }
      } while (mini[0] != mini[1] || maxi[0] != maxi[1]);
      u[x + k].insert({mini[0], maxi[0]});
      d[x + k].insert({maxi[0], mini[0]});
      l[y + k].insert({x, x});
      r[y + k].insert({x, x});
    }
    if (s[i] == 'L') {
      x--;
      mini[0] = mini[1] = x;
      maxi[0] = maxi[1] = x + 1;
      do {
        mini[1] = mini[0];
        maxi[1] = maxi[0];
        do {
          mini[1] = mini[0];
          maxi[1] = maxi[0];
          map<int, int>::iterator it = l[y + k].lower_bound(x);
          if (it != l[y + k].end() && it->second <= x) {
            x = it->second - 1;
            maxi[0] = max(maxi[0], it->first);
            mini[0] = min(mini[0], it->second - 1);
            r[y + k].erase(it->second);
            l[y + k].erase(it->first);
          }
        } while (mini[0] != mini[1] || maxi[0] != maxi[1]);
        map<int, int>::iterator it = d[x + k].lower_bound(y);
        if (it != d[x + k].end() && it->second <= y) {
          x--;
          mini[0] = x;
        }
      } while (mini[0] != mini[1] || maxi[0] != maxi[1]);
      r[y + k].insert({mini[0], maxi[0]});
      l[y + k].insert({maxi[0], mini[0]});
      u[y + k].insert({y, y});
      d[y + k].insert({y, y});
    }
    if (s[i] == 'R') {
      x++;
      mini[0] = mini[1] = x - 1;
      maxi[0] = maxi[1] = x;
      do {
        mini[1] = mini[0];
        maxi[1] = maxi[0];
        do {
          mini[1] = mini[0];
          maxi[1] = maxi[0];
          map<int, int>::iterator it = l[y + k].lower_bound(x);
          if (it != l[y + k].end() && it->second <= x) {
            x = it->first + 1;
            maxi[0] = max(maxi[0], it->first + 1);
            mini[0] = min(mini[0], it->second);
            r[y + k].erase(it->second);
            l[y + k].erase(it->first);
          }
        } while (mini[0] != mini[1] || maxi[0] != maxi[1]);
        map<int, int>::iterator it = d[x + k].lower_bound(y);
        if (it != d[x + k].end() && it->second <= y) {
          x++;
          mini[0] = x;
        }
      } while (mini[0] != mini[1] || maxi[0] != maxi[1]);
      r[y + k].insert({mini[0], maxi[0]});
      l[y + k].insert({maxi[0], mini[0]});
      u[y + k].insert({y, y});
      d[y + k].insert({y, y});
    }
  }
  cout << x << " " << y << endl;
}