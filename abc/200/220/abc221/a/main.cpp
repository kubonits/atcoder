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
  int n, m;
  ll ans = 1LL;
  cin >> n >> m;
  for (int i = m; i < n; i++) {
    ans *= 32LL;
  }
  cout << ans << endl;
}
