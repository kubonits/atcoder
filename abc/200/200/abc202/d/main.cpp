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

ll calc(ll n, ll r) {
  ll res = 1LL;
  for (ll i = 1; i <= r; i++) {
    res *= n - r + i;
    res /= i;
  }
  return res;
}

int main() {
  ll a, b, k, num;
  cin >> a >> b >> k;
  num = a + b;
  for (int i = 0; i < num; i++) {
    ll x = calc(a + b - 1, b);
    if (a != 0 && x >= k) {
      cout << "a";
      a--;
    } else {
      cout << "b";
      b--;
      k -= x;
    }
  }
  cout << endl;
}