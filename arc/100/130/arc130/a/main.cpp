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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  ll n, ans = 0LL, p = 0;
  string s;
  char c;
  cin >> n >> s;
  c = s[0];
  for (ll i = 0; i < n; i++) {
    if (s[i] != c) {
      c = s[i];
      p = i;
    }
    ans += i - p;
  }
  cout << ans << endl;
}
