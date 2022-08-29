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
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x = i, flag = 1;
    while (x) {
      if (x % 10 == 7) {
        flag = 0;
      }
      x /= 10;
    }
    x = i;
    while (x) {
      if (x % 8 == 7) {
        flag = 0;
      }
      x /= 8;
    }
    ans += flag;
  }
  cout << ans << endl;
}
