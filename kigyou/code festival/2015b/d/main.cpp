#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

int main() {
  int n, flag;
  ll s, c, x, y, z;
  map<ll, ll> l, r;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> c;
    x = s;
    flag = 1;
    map<ll, ll>::iterator it = r.lower_bound(x - 1LL);
    if (it != r.end() && it->second < x) {
      x = it->second;
      c += it->first - it->second + 1LL;
      l.erase(it->second);
      r.erase(it->first);
    }
    while (flag) {
      flag = 0;
      it = l.lower_bound(x);
      if (it != l.end() && it->first <= x + c - 1) {
        c += it->second - it->first + 1LL;
        r.erase(it->second);
        l.erase(it->first);
        flag = 1;
      }
    }
    cout << x + c - 1LL << endl;
    l.insert({x, x + c - 1LL});
    r.insert({x + c - 1LL, x});
  }
}