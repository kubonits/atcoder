#include <algorithm>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int n, a, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a != b) {
      cout << max(a, b) - min(a, b) << endl;
    } else {
      cout << -1 << endl;
    }
  }
}