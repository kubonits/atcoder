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
  int n, l = 0, r = 0;
  ll p, x = 1;
  vector<ll> a;
  cin >> n >> p;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  x = 1;
  while (l < n) {
    while (x > p) {
      x /= a[l];
      l++;
    }
    if (x == p && x >= a[l]) {
      cout << "Yay!" << endl;
      return 0;
    }
    if (r >= n) {
      break;
    }
    x *= a[r];
    r++;
  }
  cout << ":(" << endl;
}