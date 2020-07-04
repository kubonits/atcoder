#include <iostream>
using namespace std;
int main() {
  int n, t, a, sum = 0;
  cin >> n >> t;
  for (int i = 0; i < n - 1; i++) {
    cin >> a;
    sum += a;
  }
  cout << (sum + t - 1) / t << endl;
}