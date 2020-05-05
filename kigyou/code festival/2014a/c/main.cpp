#include <iostream>
using namespace std;
int main() {
  int a, b, ans;
  cin >> a >> b;
  ans = b / 400 - b / 100 + b / 4;
  a--;
  ans -= a / 400 - a / 100 + a / 4;
  cout << ans << endl;
}