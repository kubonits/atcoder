#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n, ans = 10000000;
  cin >> n;
  for (int i = 1; i * i <= n; i++) {
    ans = min(ans, n % i + n / i - i);
  }
  cout << ans << endl;
}