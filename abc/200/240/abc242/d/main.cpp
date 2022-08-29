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

string s;

char func(ll t, ll k) {
  if (t == 0) {
    return s[k];
  }
  if (k == 0) {
    return 'A' + (s[0] - 'A' + t) % 3;
  }
  if (k % 2) {
    return 'A' + (func(t - 1LL, k / 2) - 'A' + 2) % 3;
  }
  return 'A' + (func(t - 1LL, k / 2) - 'A' + 1) % 3;
}
int main() {
  int q;
  cin >> s >> q;
  while (q--) {
    ll t, k;
    cin >> t >> k;
    k--;
    cout << func(t, k) << endl;
  }
}
