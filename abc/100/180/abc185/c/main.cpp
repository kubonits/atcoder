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
  ll n, ans = 1LL;
  cin >> n;
  for (ll i = 1LL; i <= 11LL; i++) {
    ans *= (n - i);
    ans /= i;
  }
  cout << ans << endl;
}
