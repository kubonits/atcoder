#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int prime[100000];
vector<ll> p;

void init() {
  for (int i = 2; i < 100000; i++) {
    prime[i] = 1;
  }
  for (ll i = 2; i < 100000; i++) {
    if (prime[i] == 1) {
      p.push_back(i);
      for (ll j = i * i; j < 100000; j += i) {
        prime[j] = 0;
      }
    }
  }
}

int main() {
  ll n, a[100000], m, flag;
  vector<pair<ll, ll> > v;
  map<ll, ll> ma;
  cin >> n >> m;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  init();
  flag = 1;
  while (flag) {
    flag = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 1) {
        flag = 0;
      }
    }
    if (flag) {
      if (ma.find(2) == ma.end()) {
        ma.insert({2, 1});
      } else {
        ma[2]++;
      }
      for (int i = 0; i < n; i++) {
        a[i] /= 2;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (ll i = 0; i < n; i++) {
    v.clear();
    ll x = a[i];
    for (ll j = 1; p[j] * p[j] <= a[i]; j++) {
      while (x % p[j] == 0) {
        if (v.empty() || v.back().first != p[j]) {
          v.push_back({p[j], 1});
        } else {
          v.back().second++;
        }
        x /= p[j];
      }
    }
    if (x != 1) {
      v.push_back({x, 1});
    }
    for (ll j = 0; j < v.size(); j++) {
      if (ma.find(v[j].first) == ma.end()) {
        ma.insert({v[j].first, v[j].second});
      } else {
        ma[v[j].first] = max(ma[v[j].first], v[j].second);
      }
    }
  }
  map<ll, ll>::iterator it = ma.begin();
  ll x = 1;
  while (it != ma.end()) {
    for (ll i = 0; i < it->second; i++) {
      x *= it->first;
      if (x > 2LL * m) {
        cout << 0 << endl;
        return 0;
      }
    }
    it++;
  }
  x /= 2LL;
  cout << m / x / 2 + m / x % 2 << endl;
}