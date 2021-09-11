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
  int n, m, ans = 1000000000;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int cnt1 = 0, cnt2 = 0;
  while (cnt1 < n && cnt2 < m) {
    ans = min(ans, abs(a[cnt1] - b[cnt2]));
    if (a[cnt1] < b[cnt2]) {
      cnt1++;
    } else {
      cnt2++;
    }
  }
  cout << ans << endl;
}