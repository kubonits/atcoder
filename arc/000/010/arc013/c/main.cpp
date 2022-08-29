#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int n;

int main() {
  int x, y, z, xx, yy, zz, xmin, xmax, ymin, ymax, zmin, zmax, ans = 0,
                                                               maxi = 0;
  int c[3] = {}, m;
  set<int> s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    cin >> m;
    xmax = ymax = zmax = 0;
    xmin = x;
    ymin = y;
    zmin = z;
    for (int i = 0; i < m; i++) {
      cin >> xx >> yy >> zz;
      xmin = min(xmin, xx);
      xmax = max(xx, xmax);
      ymin = min(ymin, yy);
      ymax = max(ymax, yy);
      zmin = min(zmin, zz);
      zmax = max(zmax, zz);
    }
    maxi = max(maxi, max(xmax, max(ymax, zmax)));
    ans ^= xmin ^ ymin ^ zmin;
    ans ^= (x - 1 - xmax) ^ (y - 1 - ymax) ^ (z - 1 - zmax);
  }
  if (ans) {
    cout << "WIN" << endl;
  } else {
    cout << "LOSE" << endl;
  }
}