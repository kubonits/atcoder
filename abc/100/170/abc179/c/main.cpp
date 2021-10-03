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
  ll n, ans = 0;
  cin >> n;
  for (ll i = 1; i < n; i++) {
    ans += n / i;
    if (n % i == 0) {
      ans--;
    }
  }
  cout << ans << endl;
}