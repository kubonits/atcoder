#include <iostream>
using namespace std;

int main() {
  int l, x;
  cin >> l >> x;
  x %= 2 * l;
  cout << (x <= l ? x : 2 * l - x) << endl;
}