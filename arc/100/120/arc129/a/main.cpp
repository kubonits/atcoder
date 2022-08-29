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
  ll n, l, r, ans = 0LL;
  cin >> n >> l >> r;
  for (int i = 0; i < 60; i++) {
    if (n & (1LL << i)) {
      ans += max(0LL,
                 min(r, (1LL << (i + 1)) - 1LL) - max(l - 1, (1LL << i) - 1LL));
    }
  }
  cout << ans << endl;
}
