#include <iostream>
using namespace std;
int main() {
  int h, n, a;
  cin >> h >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    h -= a;
    if (h <= 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}