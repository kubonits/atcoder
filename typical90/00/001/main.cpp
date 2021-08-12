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
  int n, l, k, left = 0, right = 1000000000, mid;
  cin >> n >> l >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  a.push_back(l);
  while (left <= right) {
    mid = (right + left) / 2;
    int cnt = 0, p = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] - p >= mid) {
        cnt++;
        p = a[i];
      }
    }
    if (cnt > k) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << right << endl;
}