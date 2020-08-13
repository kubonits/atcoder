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
  int n, a, b, x = 1, y = 1, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    x *= a;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b;
    y *= b;
  }
  cout << (x == y ? "Yes" : "No") << endl;
}