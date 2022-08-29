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
  double left, right, lmid, rmid, ls, rs, n;
  cin >> n;
  vector<double> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  left = 0.0;
  right = 1000000000.0;
  for (int i = 0; i < 100; i++) {
    lmid = (2.0 * left + right) / 3.0;
    rmid = (left + 2.0 * right) / 3.0;
    ls = 0.0;
    rs = 0.0;
    for (int j = 0; j < n; j++) {
      ls += lmid + a[j] - min(a[j], 2.0 * lmid);
      rs += rmid + a[j] - min(a[j], 2.0 * rmid);
    }
    if (ls > rs) {
      left = lmid;
    } else {
      right = rmid;
    }
  }
  cout << fixed << setprecision(10) << (ls + rs) / 2.0 / n << endl;
}
