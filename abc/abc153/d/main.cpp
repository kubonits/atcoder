#include <iostream>
using namespace std;
typedef long long ll;

ll calc(ll x) {
  if (x == 1LL) {
    return 1LL;
  }
  return 1LL + 2LL * calc(x / 2LL);
}
int main() {
  ll n;
  cin >> n;
  cout << calc(n) << endl;
}