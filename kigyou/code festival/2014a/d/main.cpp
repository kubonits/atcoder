#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

ll a, k;
vector<ll> v;

ll calc(ll x, int n) {
  ll res = 0LL;
  vector<ll> b;
  for (int i = 0; i < n; i++) {
    b.push_back(x % k);
    x /= k;
  }
  reverse(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
    res *= 10LL;
    res += v[b[i]];
  }
  return res;
}
ll dfs(int x) {
  ll res = 1000000000000000000;
  if (x == 10) {
    ll right = 1LL, left = 0LL, mid;
    for (int i = 0; i < to_string(a).length(); i++) {
      right *= k;
    }
    while (left <= right) {
      mid = (left + right) / 2LL;
      ll c = calc(mid, to_string(a).length());
      if (c == a) {
        return 0LL;
      } else if (c < a) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (right >= 0LL) {
      res = min(res, abs(a - calc(right, to_string(a).length())));
    }
    res = min(res, abs(calc(left, to_string(a).length()) - a));

    right = 1LL, left = 0LL;
    for (int i = 0; i < to_string(a).length() + 1; i++) {
      right *= k;
    }
    while (left <= right) {
      mid = (left + right) / 2LL;
      ll c = calc(mid, to_string(a).length() + 1);
      if (c == a) {
        return 0LL;
      } else if (c < a) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (right >= 0LL) {
      res = min(res, abs(a - calc(right, to_string(a).length() + 1)));
    }
    res = min(res, abs(calc(left, to_string(a).length() + 1) - a));
    right = 1LL, left = 0LL;
    for (int i = 0; i < to_string(a).length() - 1; i++) {
      right *= k;
    }
    while (left <= right) {
      mid = (left + right) / 2LL;
      ll c = calc(mid, to_string(a).length() - 1);
      if (c == a) {
        return 0LL;
      } else if (c < a) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (right >= 0LL) {
      res = min(res, abs(a - calc(right, to_string(a).length() - 1)));
    }
    res = min(res, abs(calc(left, to_string(a).length() + -1) - a));
    return res;
  }
  if (v.size() < k) {
    v.push_back(x);
    res = min(res, dfs(x + 1));
    v.pop_back();
  }
  if (v.size() + 9 - x >= k) {
    res = min(res, dfs(x + 1));
  }
  return res;
}

int main() {
  cin >> a >> k;
  cout << dfs(0) << endl;
}