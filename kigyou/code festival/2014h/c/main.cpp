#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  ll n, a, b = 10000000000000000LL;
  cin >> n;
  for (ll i = 11LL; i <= 10000LL; i++) {
    ll x = i;
    a = 0LL;
    b = 10000LL;
    while (b) {
      a *= i;
      if (x / b) {
        a += x / b;
        x -= x / b * b;
      }
      b /= 10LL;
    }
    if (a == n) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}