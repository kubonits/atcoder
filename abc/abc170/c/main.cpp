#include <algorithm>
#include <cmath>
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

int main() {
  int n, x, p, ans = 10000;
  cin >> x >> n;
  vector<int> v(110);
  for (int i = 0; i < 110; i++) {
    v[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> p;
    v[p] = 1;
  }
  ans = -1;
  for (int i = 0; i < 110; i++) {
    if (v[i] == 0 && (abs(ans - x) > abs(i - x) ||
                      (abs(ans - x) == abs(i - x) && ans > i))) {
      ans = i;
    }
  }
  cout << ans << endl;
}