#include <iostream>
using namespace std;
int main() {
  int n;
  long long ans = 1LL, b = 1LL;
  cin >> n;
  for (int i = 0; i < n; i++) {
    b *= 5;
    ans += b;
  }
  cout << ans << endl;
}