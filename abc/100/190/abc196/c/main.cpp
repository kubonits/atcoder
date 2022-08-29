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
  for (int i = 1; i < n; i++) {
    string s = to_string(i);
    s += s;
    if (n >= stoll(s)) {
      ans++;
    } else {
      cout << ans << endl;
      return 0;
    }
  }
  cout << ans << endl;
}
