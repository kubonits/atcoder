#include <iostream>
using namespace std;
int main() {
  int n, k, a[200000], ans = -1, p = -1;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (k > a[i] && ans < a[i]) {
      ans = a[i];
      p = i + 1;
    }
  }
  cout << p << endl;
}