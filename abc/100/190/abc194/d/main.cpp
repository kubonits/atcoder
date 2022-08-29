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
  double n;
  double ans = 0.0;
  cin >> n;
  for (double i = 1.0; i < n; i++) {
    ans += 1.0 / (1.0 - ((n - i) / n));
  }
  cout << fixed << setprecision(15) << ans << endl;
}
