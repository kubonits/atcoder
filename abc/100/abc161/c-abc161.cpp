#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int main() {
  ll n, k;
  scanf("%lld%lld", &n, &k);
  set<ll> s;
  s.insert(n % k);
  n %= k;
  while (1) {
    if (s.find(k - n) != s.end()) {
      break;
    } else {
      n = k - n;
      s.insert(n);
    }
  }
  printf("%lld\n", *s.begin());
}