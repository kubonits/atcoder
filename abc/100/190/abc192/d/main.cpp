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
  string s;
  ll x, a, ans = 0LL, left = 0, right = 1000000000000000000, mid, z = 0;
  cin >> s >> x;
  if (s.length() == 1) {
    cout << (stoi(s) <= x ? 1 : 0) << endl;
    return 0;
  }
  for (int i = 0; i < s.length(); i++) {
    z = max(z, (ll)(s[i] - '0'));
  }
  left = z;
  while (left <= right) {
    int flag = 1;
    mid = (left + right) / 2LL;
    ll y = 0;
    for (int i = 0; i < s.length(); i++) {
      if (x / mid >= y) {
        y *= mid;
        y += (s[i] - '0');
      } else {
        flag = 0;
        break;
      }
    }
    if (flag && x >= y) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << max(0LL, right - z) << endl;
}
