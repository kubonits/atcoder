#include <iostream>
using namespace std;
int main() {
  int n, a, sum = 0, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    sum += a;
    if (sum <= 2018) {
      ans++;
    }
  }
  cout << ans << endl;
}