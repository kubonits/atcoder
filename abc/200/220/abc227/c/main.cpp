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
  ll n, ans = 0;
  cin >> n;
  for (ll i = 1; i <= 4641; i++) {
    for (ll j = i; i * j * j <= n; j++) {
      ans += n / (i * j) - j + 1;
    }
  }
  cout << ans << endl;
}
