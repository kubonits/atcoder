#include <iostream>
using namespace std;
int main() {
  int n, a[46] = {}, ans = 0;
  cin >> n;
  a[0] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= i - 2; j++) {
      a[i] += a[j];
    }
  }
  for (int i = 0; i <= n; i++) {
    ans += a[i];
  }
  cout << ans << endl;
}