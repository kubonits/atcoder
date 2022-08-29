#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> v;
int main() {
  ll n, x, y;
  cin >> n;
  for (ll i = max(0LL, n - 200LL); i <= n; i++) {
    y = i;
    x = i;
    while (x) {
      y += x % 10LL;
      x /= 10LL;
    }
    if (y == n) {
      v.push_back(i);
    }
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}