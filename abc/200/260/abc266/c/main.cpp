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
  int x[4], y[4];
  for (int i = 0; i < 4; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < 4; i++) {
    if ((x[(i + 1) % 4] - x[i]) * (y[(i + 3) % 4] - y[i]) -
            (y[(i + 1) % 4] - y[i]) * (x[(i + 3) % 4] - x[i]) <=
        0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
