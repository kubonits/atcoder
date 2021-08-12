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

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int a, b, c, d, ans = 0;
  cin >> a >> b >> c >> d;
  ans = abs(a - c) + abs(b - d);
  ans -= gcd(abs(a - c), abs(b - d));
  cout << ans << endl;
}