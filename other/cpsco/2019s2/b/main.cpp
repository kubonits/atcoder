#include <iostream>
#include <string>

using namespace std;
int main() {
  int n, a, ans = 0, b = 1;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> a;
    if (s == "*" && a) {
      b *= a;
    } else if (s == "+") {
      ans += a;
    }
  }
  cout << ans * b << endl;
}