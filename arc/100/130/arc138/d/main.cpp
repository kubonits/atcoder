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

set<ll> t;

vector<ll> calc(ll n, ll a) {
  if (n == 0LL) {
    return {0LL};
  } else {
    vector<ll> v = calc(n - 1LL, a);
    if (t.empty()) {
      cout << "error" << endl;
      return {};
    }
    ll x = *t.begin();
    for (int i = v.size() - 1; i >= 0; i--) {
      v.push_back(v[i] ^ x);
      t.erase(v.back());
    }
    return v;
  }
}

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  ll n, k, x = 1LL;
  cin >> n >> k;
  if (n == 1LL && k == 1LL) {
    cout << "Yes" << endl;
    cout << "0 1" << endl;
    return 0;
  }
  if (n == k || k % 2 == 0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  for (int i = 0; i < (1 << n); i++) {
    int x = i;
    int cnt = 0;
    while (x) {
      cnt += x % 2;
      x /= 2;
    }
    if (cnt == k) {
      t.insert(i);
    }
  }
  // for (ll i = 1LL; i <= 18LL; i++) {
  //   for (ll j = 1LL; j < i; j += 2LL) {
  //     vector<ll> ans = calc(i, i - 1LL, (((1LL << j) - 1LL) << (i - j)));
  //     set<ll> s;
  //     for (int k = 0; k < ans.size(); k++) {
  //       ll x = ans[k] ^ ans[(k + 1) % ans.size()];
  //       s.insert(ans[k]);
  //       int cnt = 0;
  //       while (x) {
  //         cnt += x % 2LL;
  //         x /= 2LL;
  //       }
  //       // if (cnt != j) {
  //       //   cout << i << " " << j << endl;
  //       // }
  //     }
  //     if (s.size() != ans.size()) {
  //       // cout << i << " " << j << endl;
  //       // for (int k = 0; k < ans.size(); k++) {
  //       //   cout << ans[k] << endl;
  //       // }
  //       return 0;
  //     }
  //   }
  // }
  vector<ll> ans = calc(n, n - 1LL);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
