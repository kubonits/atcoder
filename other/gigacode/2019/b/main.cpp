#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, a, b, x, y, z, ans = 0;
  cin >> n >> x >> y >> z;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if ((a >= x && b >= y) && a + b >= z) {
      ans++;
    }
  }
  cout << ans << endl;
}