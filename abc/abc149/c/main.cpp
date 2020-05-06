#include <iostream>
using namespace std;

int main() {
  int n, flag;
  cin >> n;
  for (int i = n; i <= 100003; i++) {
    flag = 1;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      cout << i << endl;
      return 0;
    }
  }
}