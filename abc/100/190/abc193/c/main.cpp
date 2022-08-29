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
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  ll n, x;
  set<ll> s;
  cin >> n;
  for (ll i = 2; i <= sqrt(n); i++) {
    x = i * i;
    while (x <= n) {
      s.insert(x);
      x *= i;
    }
  }
  cout << n - s.size() << endl;
}
