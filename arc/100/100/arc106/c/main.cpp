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
  int n, m;
  cin >> n >> m;
  if (n == 1 && m == 0) {
    cout << 1 << " " << 2 << endl;
    return 0;
  }
  if (abs(m) + 1 >= n || m < 0) {
    cout << -1 << endl;
    return 0;
  }
  if (m == 0) {
    for (int i = 1; i <= n; i++) {
      cout << 2 * i << " " << 2 * i + 1 << endl;
    }
    return 0;
  }
  if (m > 0) {
    cout << 1 << " " << 1000000 << endl;
    for (int i = 0; i <= m; i++) {
      cout << 2 + 2 * i << " " << 3 + 2 * i << endl;
    }
    for (int i = 0; i < n - (m + 2); i++) {
      cout << 1000001 + 2 * i << " " << 1000002 + 2 * i << endl;
    }
    return 0;
  }
}
