#include <iostream>
using namespace std;
int main() {
  int n, m, sum = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    sum += i * i;
  }
  cout << sum % m << endl;
}