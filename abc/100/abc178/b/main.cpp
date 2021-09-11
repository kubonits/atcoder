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
  ll a, b, c, d, ans = -1000000000000000000;
  cin >> a >> b >> c >> d;
  ans = max(ans, a * c);
  ans = max(ans, a * d);
  ans = max(ans, b * c);
  ans = max(ans, b * d);
  cout << ans << endl;
}