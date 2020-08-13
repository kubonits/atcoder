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
  int n, ans = 0, t, d, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t >> d >> m;
    if (t + 10 <= d) {
      ans += m;
    }
  }
  cout << ans << endl;
}