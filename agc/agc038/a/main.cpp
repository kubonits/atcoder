//解説AC
#include <iostream>
using namespace std;

int main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  if (w / 2 < a || h / 2 < b) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int x = 0, y = 0;
      if (i < b) {
        y = 1;
      }
      if (j < a) {
        x = 1;
      }
      cout << (x ^ y);
    }
    cout << endl;
  }
}