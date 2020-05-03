#include <iostream>
using namespace std;
int main() {
  long long h, w;
  cin >> h >> w;
  if (h == 1LL || w == 1LL) {
    cout << 1 << endl;
  } else if (h % 2LL && w % 2LL) {
    cout << h * w / 2LL + 1LL << endl;
  } else {
    cout << h * w / 2LL << endl;
  }
}