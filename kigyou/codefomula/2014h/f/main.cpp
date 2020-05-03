#include <iostream>
#include <vector>
using namespace std;

int main() {
  int sum1 = 1500, p = 0;
  int sum2 = 0;
  vector<int> x, y;
  for (int i = 100; i >= 1; i--) {
    if (sum1 + 2 * i > 1500) {
      sum2 += 2 * i;
      sum1 = 2 * i;
      p = i;
      x.push_back(i);
      y.push_back(sum2 - p);
    } else {
      x.push_back(sum1 + i);
      y.push_back(sum2 - p);
      sum1 += 2 * i;
    }
  }
  for (int i = 99; i >= 0; i--) {
    cout << x[i] << " " << y[i] << endl;
  }
}