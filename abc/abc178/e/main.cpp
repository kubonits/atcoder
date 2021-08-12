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
  int n, x, y, pmin, pmax, mmin, mmax;
  cin >> n;
  cin >> x >> y;
  pmin = pmax = x + y;
  mmin = mmax = x - y;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    pmin = min(pmin, x + y);
    pmax = max(pmax, x + y);
    mmin = min(mmin, x - y);
    mmax = max(mmax, x - y);
  }
  cout << max(pmax - pmin, mmax - mmin) << endl;
}