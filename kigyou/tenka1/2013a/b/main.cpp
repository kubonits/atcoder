#include <iostream>
using namespace std;

int main() {
  int n, sum = 0, ans = 0, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    sum = 0;
    for (int j = 0; j < 5; j++) {
      cin >> a;
      sum += a;
    }
    if (sum < 20) {
      ans++;
    }
  }
  cout << ans << endl;
}