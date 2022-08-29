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
  ll n, maxi = 0, ans = 0LL;
  cin >> n;
  vector<ll> a(n), sum(n + 1);
  for (ll i = 0LL; i < n; i++) {
    cin >> a[i];
    sum[i + 1] = sum[i] + a[i];
    maxi = max(maxi, a[i]);
    cout << maxi * (i + 1LL) + ans + sum[i + 1] << endl;
    ans += sum[i + 1];
  }
}
