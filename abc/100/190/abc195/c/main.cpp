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
  ll n, ans = 0LL;
  cin >> n;
  if (n > 999) {
    ans += n - 999;
  }
  if (n > 999999) {
    ans += n - 999999;
  }
  if (n > 999999999) {
    ans += n - 999999999;
  }
  if (n > 999999999999) {
    ans += n - 999999999999;
  }
  if (n > 999999999999999) {
    ans += n - 999999999999999;
  }
  cout << ans << endl;
}
