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
  int a, b, x;
  cin >> a >> b;
  x = 1000000000;
  while (a > 1 && b > 1) {
    cout << x << " " << -x << " ";
    a--;
    b--;
    x--;
  }
  for (int i = 1; i <= max(a, b); i++) {
    cout << (a > b ? 1 : -1) * i << " ";
  }
  cout << (a > b ? -1 : 1) * max(a, b) * (a + b) / 2 << endl;
}
