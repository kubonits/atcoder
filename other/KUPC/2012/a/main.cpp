#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n, t, e, x[100];
  cin >> n >> t >> e;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = max(0, t - e); j <= t + e; j++) {
      if (j % x[i] == 0) {
        cout << i + 1 << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}