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
  ll n, a = 3LL, b, cnt1 = 1LL, cnt2;
  cin >> n;
  while (a <= n) {
    b = n - a;
    cnt2 = 0LL;
    while (b != 0 && b % 5 == 0) {
      b /= 5LL;
      cnt2++;
    }
    if (b == 1LL && cnt2 > 0LL) {
      cout << cnt1 << " " << cnt2 << endl;
      return 0;
    }
    if (a > n / 3LL) {
      break;
    }
    a *= 3LL;
    cnt1++;
  }
  cout << -1 << endl;
}