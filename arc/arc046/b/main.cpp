#include <iostream>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a == b) {
    if (n % (a + 1) != 0) {
      cout << "Takahashi" << endl;
    } else {
      cout << "Aoki" << endl;
    }
    return 0;
  } else if (a > b || a >= n) {
    cout << "Takahashi" << endl;
    return 0;
  }
  cout << "Aoki" << endl;
}