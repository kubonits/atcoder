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
  ll ans = 0LL;
  cin >> n;
  vector<int> a(n);
  vector<ll> b(200);
  for (int i = 0; i < 200; i++) {
    b[i] = 0LL;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i] % 200]++;
  }
  for (int i = 0; i < 200; i++) {
    ans += b[i] * (b[i] - 1LL) / 2LL;
  }
  cout << ans << endl;
}
