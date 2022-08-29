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
  int n, a, b, c;
  cin >> n;
  a = n % 10;
  n /= 10;
  b = n % 10;
  c = n / 10;
  cout << 111 * (a + b + c) << endl;
}
