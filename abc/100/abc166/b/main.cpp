#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n, k, a[100] = {}, d, b, ans = 0;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> d;
    for (int j = 0; j < d; j++) {
      cin >> b;
      b--;
      a[b] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      ans++;
    }
  }
  cout << ans << endl;
}