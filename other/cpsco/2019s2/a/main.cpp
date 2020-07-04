#include <iostream>
using namespace std;
int main() {
  int n, m;
  cin >> m >> n;
  cout << m - m / n * (n - 1) << endl;
}