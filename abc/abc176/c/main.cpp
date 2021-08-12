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
  int n;
  ll a, x, ans = 0LL;
  cin >> n >> a;
  x = a;
  for (int i = 0; i < n - 1; i++) {
    cin >> a;
    ans += max(0LL, x - a);
    x = max(x, a);
  }
  cout << ans << endl;
}