#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int a, b, x[100];
  cin >> a >> b;
  for (int i = 0; i < 100; i++) {
    x[i] = 100;
  }
  x[a] = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j <= 40; j++) {
      if (j - 1 >= 0) {
        x[j - 1] = min(x[j - 1], x[j] + 1);
      }
      if (j - 5 >= 0) {
        x[j - 5] = min(x[j - 5], x[j] + 1);
      }
      if (j - 10 >= 0) {
        x[j - 10] = min(x[j - 10], x[j] + 1);
      }
      x[j + 1] = min(x[j + 1], x[j] + 1);
      x[j + 5] = min(x[j + 5], x[j] + 1);
      x[j + 10] = min(x[j + 10], x[j] + 1);
    }
  }
  cout << x[b] << endl;
}