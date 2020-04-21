#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n, a, b, c;
  cin >> a >> b >> c >> n;
  cout << max(0, n - a) << " " << max(0, 2 * n - b) << " " << max(0, 3 * n - c)
       << endl;
}