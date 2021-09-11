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
  int n, q;
  ll a, b, left, right, mid, l, r, m;
  cin >> n >> q;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < q; i++) {
    cin >> a;
    b = a;
    left = 0;
    right = n - 1;
    while (left <= right) {
      mid = (right + left) / 2LL;
      if (v[mid] - mid > a) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    cout << a + left << endl;
  }
}