#include <algorithm>
#include <cmath>
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
  ll n, k, ans = 0LL;
  cin >> n;
  for (ll i = 1; i <= n; i++) {
    for (ll j = i; j <= n; j += i) {
      ans += j;
    }
  }
  cout << ans << endl;
}