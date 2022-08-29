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
  int n, d, l, r, ans = 0, p = -1;
  cin >> n >> d;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    v.push_back({r, l});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (v[i].second > p) {
      ans++;
      p = v[i].first + d - 1;
    }
  }
  cout << ans << endl;
}
