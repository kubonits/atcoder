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
  int n, a;
  ll ans = 0LL;
  cin >> n;
  vector<ll> v(n + 1), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a;
    v[a]++;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    c[i]--;
    ans += v[b[c[i]]];
  }
  cout << ans << endl;
}