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
  ll n;
  cin >> n;
  set<ll> s;
  while (n % 2 == 0) {
    n /= 2LL;
  }
  for (ll i = 1LL; i <= sqrt(n); i++) {
    if (n % i == 0) {
      s.insert(i);
      s.insert(n / i);
    }
  }

  cout << s.size() * 2LL << endl;
}
