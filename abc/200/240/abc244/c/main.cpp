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
  int n;
  cin >> n;
  vector<int> v(2 * n + 2);
  int x;
  while (1) {
    for (int i = 1; i <= 2 * n + 1; i++) {
      if (v[i] == 0) {
        cout << i << "\n" << flush;
        v[i] = 1;
        break;
      }
    }
    cin >> x;
    v[x] = 1;
    if (x == 0) {
      return 0;
    }
  }
}
