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
  int n, m, t, now = 0, a, b, maxi;
  cin >> n >> m >> t;
  maxi = n;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    n -= (a - now);
    if (n <= 0) {
      cout << "No" << endl;
      return 0;
    }
    n = min(maxi, n + b - a);
    now = b;
  }
  cout << (n - t + now > 0 ? "Yes" : "No") << endl;
}
