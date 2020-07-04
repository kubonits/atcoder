#include <algorithm>
#include <cmath>
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

int main() {
  ll n, a, b, c, q, ans = 0LL;
  cin >> n;
  vector<ll> v(100001);
  for (int i = 0; i < n; i++) {
    cin >> a;
    v[a]++;
    ans += a;
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> b >> c;
    ans += (c - b) * v[b];
    v[c] += v[b];
    v[b] = 0LL;
    cout << ans << endl;
  }
}