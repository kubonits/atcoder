#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 100; i++) {
    if (i * i * i == n) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}