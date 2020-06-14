#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
  int n;
  string op;
  set<int> s, d;
  cin >> n >> op;
  if ((n == 1 || n == 2) && op == "=") {
    for (int i = 0; i < n; i++) {
      cout << i << " ";
    }
    cout << endl;
    return 0;
  } else if ((n == 1 || n == 2) || (n < 8 && op == ">")) {
    cout << "Merry Christmas!" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (op == "=") {
      cout << i << " ";
    } else if (op == "<") {
      cout << i * (i + 1) / 2 << " ";
    } else if (i < 2) {
      cout << i * 2 << " ";
    } else if (i == 2) {
      cout << 3 << " ";
    } else if (i == 3) {
      cout << 4 << " ";
    } else if (i < n - 2) {
      cout << 4 * i - 9 << " ";
    } else {
      cout << 2 * i << " ";
    }
  }
  cout << endl;
}