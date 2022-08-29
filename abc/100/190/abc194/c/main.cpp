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
  ll ans = 0;
  cin >> n;
  vector<ll> v(401);
  for (int i = 0; i < n; i++) {
    cin >> a;
    v[a + 200]++;
  }
  for (ll i = 0LL; i < 401LL; i++) {
    for (ll j = i + 1LL; j < 401LL; j++) {
      ans += (j - i) * (j - i) * v[i] * v[j];
    }
  }
  cout << ans << endl;
}
