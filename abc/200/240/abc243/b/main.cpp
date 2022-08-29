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
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  ans *= -1;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int p = 0;
  for (int i = 0; i < n; i++) {
    while (p < n && a[i] > b[p]) {
      p++;
    }
    if (p < n && a[i] == b[p]) {
      ans++;
      p++;
    }
  }
  cout << ans << endl;
}
