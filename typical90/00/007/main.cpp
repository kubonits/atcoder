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
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int q, b;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> b;
    int left = 0, right = n - 1, mid;
    while (left <= right) {
      mid = (left + right) / 2;
      if (v[mid] > b) {
        right = mid - 1;
      } else if (v[mid] < b) {
        left = mid + 1;
      } else {
        left = mid;
        right = mid - 1;
      }
    }
    if (right < 0) {
      cout << abs(b - v[left]) << endl;
    } else if (left == n) {
      cout << abs(b - v[right]) << endl;
    } else {
      cout << min(abs(b - v[left]), abs(b - v[right])) << endl;
    }
  }
}