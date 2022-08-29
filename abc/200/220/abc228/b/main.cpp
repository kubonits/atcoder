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
  int n, x, ans = 0;
  cin >> n >> x;
  x--;
  vector<int> a(n), f(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  while (f[x] == 0) {
    f[x] = 1;
    x = a[x];
    ans++;
  }
  cout << ans << endl;
}
