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
  ll r, x, y;
  cin >> r >> x >> y;
  cout << (r * r > x * x + y * y ? 2 : ceil(sqrt(x * x + y * y) / r)) << endl;
}
