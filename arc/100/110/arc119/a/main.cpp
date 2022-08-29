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
  ll n, ans = 1000000000000000000;
  cin >> n;
  for (ll i = 0; pow(2LL, i) <= n; i++) {
    ans = min(ans, n / (ll)pow(2, i) + i + n % (ll)pow(2, i));
  }
  cout << ans << endl;
}
