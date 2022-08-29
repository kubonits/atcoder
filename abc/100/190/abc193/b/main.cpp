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
  int n, ans = MOD, a, p, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> p >> x;
    if (a < x) {
      ans = min(ans, p);
    }
  }
  cout << (ans == MOD ? -1 : ans) << endl;
}
