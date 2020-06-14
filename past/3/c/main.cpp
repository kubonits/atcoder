#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  ll a, r, n;
  cin >> a >> r >> n;
  if (r == 1) {
    cout << a << endl;
    return 0;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a * r > 1000000000LL) {
      cout << "large" << endl;
      return 0;
    }
    a *= r;
  }
  cout << a << endl;
}