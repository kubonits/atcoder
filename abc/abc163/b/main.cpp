#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
  int n, m, sum = 0, a[10000];
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum > n) {
    cout << -1 << endl;
  } else {
    cout << n - sum << endl;
  }
}