#include <iostream>
using namespace std;

bool is_prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return n != 1;  // 1の場合は例外
}

int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 2; i < n; i++) {
    if (is_prime(i)) {
      ans++;
    }
  }
  cout << ans << endl;
}