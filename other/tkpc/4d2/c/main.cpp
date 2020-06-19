#include <iostream>
using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;
  if (b % 4 && (b % 4 != 3 || a % 2)) {
    cout << "Angel" << endl;
  } else {
    cout << "Devil" << endl;
  }
}