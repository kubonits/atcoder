#include <iostream>
using namespace std;

int a[200000];

int main() {
  int b, ans = 0;
  cin >> b;
  a[b] = 1;
  for (int i = b - 1; i >= 2; i--) {
    if (a[i + i / 2]) {
      a[i] = 1;
      ans++;
    }
  }
  cout << ans << endl;
}