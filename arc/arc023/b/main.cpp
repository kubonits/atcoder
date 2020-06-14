#include <algorithm>
#include <iostream>
using namespace std;
int a[1000][1000];
int main() {
  int r, c, d, ans = 0;
  cin >> r >> c >> d;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
      if (i + j <= d && (i + j) % 2 == d % 2) {
        ans = max(ans, a[i][j]);
      }
    }
  }
  cout << ans << endl;
}