#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

void solve(ll n) {
  ll r = sqrt(n);
  ll ans = 0;
  for (ll i = 2; i <= r; i++) {
    ll num = n;
    while (num % i == 0) {
      num /= i;
    }
    if (num % i == 1) {
      ans++;
    }
    if ((i * i != n - 1) && (n - 1) % i == 0) {
      ans++;
    }
  }
  printf("%d\n", ans + 2);
}

int main() {
  ll n;
  int ans = 0;
  scanf("%lld", &n);
  if (n == 2) {
    printf("1\n");
  } else {
    solve(n);
  }
}