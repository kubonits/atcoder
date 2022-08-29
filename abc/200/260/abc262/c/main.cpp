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
  ll n, ans = 0LL, cnt = 0LL;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0LL; i < n; i++) {
    cin >> a[i];
    a[i]--;
    if (a[i] == i) {
      cnt++;
    }
  }
  for (ll i = 0LL; i < n; i++) {
    if (a[i] != i) {
      if (a[a[i]] == i) {
        ans++;
      }
    }
  }
  cout << ans / 2LL + cnt * (cnt - 1LL) / 2LL << endl;
}
