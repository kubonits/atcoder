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
  int n, p, a, ans = 0;
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a < p) {
      ans++;
    }
  }
  cout << ans << endl;
}
