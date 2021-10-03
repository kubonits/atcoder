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
  int n;
  ll ans = 0LL, a, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    ans += b * (b + 1LL) / 2LL;
    ans -= a * (a - 1LL) / 2LL;
  }
  cout << ans << endl;
}