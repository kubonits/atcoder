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
  int n, x, v, p;
  cin >> n >> x;
  x *= 100;
  for (int i = 1; i <= n; i++) {
    cin >> v >> p;
    x -= v * p;
    if (x < 0) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
