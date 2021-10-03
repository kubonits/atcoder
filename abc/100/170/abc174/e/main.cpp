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
  int n, k, cnt;
  double l = 0.0, r = 1000000000, mid;
  cin >> n >> k;
  vector<double> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 100; i++) {
    mid = (l + r) / 2.0;
    cnt = 0;
    for (int j = 0; j < n; j++) {
      cnt += (int)floor(a[j] / mid);
    }
    if (cnt <= k) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << (int)ceil(mid) << endl;
}