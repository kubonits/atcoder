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
  int n, q, x, left, right, mid;
  cin >> n >> q;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < q; i++) {
    cin >> x;
    left = 0;
    right = n - 1;
    while (left <= right) {
      mid = (left + right) / 2;
      if (v[mid] >= x) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    cout << n - left << endl;
  }
}
