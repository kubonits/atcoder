#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  ll n, cnt = 0LL;
  vector<ll> a(50);
  cin >> n;
  a[0] = 0LL;
  a[1] = 1LL;
  for (int i = 2; i < 50; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }
  for (int i = 49; i > 0; i--) {
    while (n >= a[i]) {
      n -= a[i];
      cnt++;
    }
  }
  cout << cnt << endl;
}