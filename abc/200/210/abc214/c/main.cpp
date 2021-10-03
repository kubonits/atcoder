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
  int n, p, mini;
  cin >> n;
  vector<ll> s(n), t(n), ans(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    ans[i] = t[i];
  }
  for (int i = 0; i < 3 * n; i++) {
    ans[(i + 1) % n] = min(ans[i % n] + s[i % n], ans[(i + 1) % n]);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}