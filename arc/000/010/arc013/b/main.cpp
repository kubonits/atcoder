#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int c, a[100][4], sum = 0, b[3] = {};
  cin >> c;
  for (int i = 0; i < c; i++) {
    a[i][3] = 1;
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
      a[i][3] *= a[i][j];
    }
    sort(a[i], a[i] + 3);
    sum += a[i][3];
  }
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < 3; j++) {
      b[j] = max(b[j], a[i][j]);
    }
  }
  cout << b[0] * b[1] * b[2] << endl;
}