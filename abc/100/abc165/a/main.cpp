#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int a, b, n;
  cin >> n >> a >> b;
  for (int i = a; i <= b; i++) {
    if (i % n == 0) {
      cout << "OK" << endl;
      return 0;
    }
  }
  cout << "NG" << endl;
}