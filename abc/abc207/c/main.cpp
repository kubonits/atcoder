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
  int n, ans = 0, left, right, tt;
  cin >> n;
  vector<int> t(n), l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> l[i] >> r[i];
    t[i]--;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      tt = 0;
      if (l[i] > l[j]) {
        left = l[i];
        tt |= (2 & t[i]);
      } else if (l[i] < l[j]) {
        left = l[j];
        tt |= (2 & t[j]);
      } else {
        left = l[i];
        tt |= (2 & (t[j] | t[i]));
      }
      if (r[i] < r[j]) {
        right = r[i];
        tt |= (1 & t[i]);
      } else if (r[i] > r[j]) {
        right = r[j];
        tt |= (1 & t[j]);
      } else {
        right = r[i];
        tt |= (1 & (t[j] | t[i]));
      }
      if (left < right) {
        ans++;
      } else if (left == right && tt == 0) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}