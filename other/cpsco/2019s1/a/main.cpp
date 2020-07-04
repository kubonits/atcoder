#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  cout << (a + 2) / 3 << " " << min(n / 3, a) << endl;
}