#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int sum[100] = {};
  for (int i = 20; i < 100000; i++) {
    sum[(int)(floor(20 / (log(i) / log(20)))) - 4]++;
  }
  for (int i = 0; i < 30; i++) {
    cout << sum[i] << endl;
  }
}