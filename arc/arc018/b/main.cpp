#include <iostream>
using namespace std;
int main() {
  long long n, x[100], y[100], ans = 0, s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        s = (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]);
        if (s && s % 2LL == 0) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}