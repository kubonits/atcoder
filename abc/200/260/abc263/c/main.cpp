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
  int n, m;
  cin >> n >> m;
  for (int i = (1 << m) - 1; i >= 0; i--) {
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      if (i & (1 << j)) {
        cnt++;
      }
    }
    if (cnt == n) {
      for (int j = m; j > 0; j--) {
        if (i & (1 << (j - 1))) {
          cout << m - j + 1 << " ";
        }
      }
      cout << endl;
    }
  }
}
