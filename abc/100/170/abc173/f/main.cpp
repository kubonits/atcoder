#include <algorithm>
#include <cmath>
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
  ll n, a, b;
  cin >> n;
  ll ans = 0;
  for (ll i = 1LL; i <= n; i++) {
    ans += i * (n - i + 1);
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    ans -= min(a, b) * (n - max(a, b) + 1);
  }
  cout << ans << endl;
}