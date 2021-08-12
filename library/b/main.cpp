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

ll bit[500001], n;

ll sum(ll i) {
  ll s = 0;
  while (i > 0) {
    s += bit[i];
    i -= (i & -i);
  }
  return s;
}

void add(ll i, ll x) {
  while (i <= n) {
    bit[i] += x;
    i += (i & -i);
  }
}

int main() {
  int q;
  ll a, b, c;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a;
    add(i + 1, a);
  }
  while (q--) {
    cin >> a >> b >> c;
    if (a == 0) {
      add(b + 1, c);
    } else {
      cout << sum(c) - sum(b) << endl;
    }
  }
}