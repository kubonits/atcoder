#include <iostream>
using namespace std;
int main() {
  int n, x, k, sum[1001], p;
  cin >> n >> x;
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + n - i + 1;
    if (x <= sum[i]) {
      k = i * 10000;
      p = sum[i] - x;
      break;
    }
  }
  cout << k << endl;
  for (int i = 0; i < n; i++) {
    if (i < p) {
      cout << 10001 << " ";
    } else {
      cout << 10000 << " ";
    }
  }
  cout << endl;
}