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

int bit[300001], n;

int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= (i & -i);
  }
  return s;
}

void add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += (i & -i);
  }
}

int main() {
  ll ans = 0LL;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    v[i]++;
    add(v[i], 1);
    ans += sum(n) - sum(v[i]);
  }
  cout << ans << endl;
  for (int i = 0; i < n - 1; i++) {
    ans += n - 1 - 2 * (v[i] - 1);
    cout << ans << endl;
  }
}
