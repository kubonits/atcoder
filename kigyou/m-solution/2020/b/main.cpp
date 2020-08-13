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
  int n, a, b, c;
  cin >> a >> b >> c >> n;
  while (a >= b) {
    b *= 2;
    n--;
  }
  while (b >= c) {
    c *= 2;
    n--;
  }
  cout << (n >= 0 ? "Yes" : "No") << endl;
}