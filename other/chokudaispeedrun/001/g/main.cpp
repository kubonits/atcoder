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

int main() {
  int n;
  cin >> n;
  ll ans = 1LL, a;
  cin >> ans;
  for (int i = 1; i < n; i++) {
    cin >> a;
    for (int j = 0; j < to_string(a).length(); j++) {
      ans *= 10LL;
      ans %= MOD;
    }
    ans += a;
    ans %= MOD;
  }
  cout << ans << endl;
}