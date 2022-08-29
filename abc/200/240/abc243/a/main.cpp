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
  cin >> n >> a >> b >> c;
  n %= (a + b + c);
  if (n < a) {
    cout << "F" << endl;
    return 0;
  }
  n -= a;
  if (n < b) {
    cout << "M" << endl;
    return 0;
  }
  cout << "T" << endl;
}
