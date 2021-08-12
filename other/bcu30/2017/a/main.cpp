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
  int n, k, ans = 0, a;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> a;
    ans += a;
    if (ans == n) {
      cout << n << endl;
      return 0;
    }
    if (ans > n) {
      ans = n - (ans - n);
    } else if (ans < 0) {
      ans = -ans;
    }
  }
  cout << ans << endl;
}