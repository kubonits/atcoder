#include <iostream>
using namespace std;

int main() {
  int n, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a % 2 == 0 && (a % 5 && a % 3)) {
      cout << "DENIED" << endl;
      return 0;
    }
  }
  cout << "APPROVED" << endl;
}