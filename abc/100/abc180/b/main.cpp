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
  int n;
  ll a, b, c, x;
  a = b = c = 0LL;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a += abs(x);
    b += x * x;
    c = max(c, abs(x));
  }
  cout << a << endl;
  cout << fixed << setprecision(10) << (double)sqrt(b) << endl;
  cout << c << endl;
}