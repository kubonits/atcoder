#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n, m, l[2], r[2];
  cin >> n >> m;
  l[0] = 1;
  r[0] = 1 + m;
  l[1] = m + 2;
  r[1] = m + 2 + m - 1;
  for (int i = 0; i < m; i++) {
    if (i % 2 == 0) {
      cout << l[0] << " " << r[0] << endl;
      l[0]++;
      r[0]--;
    } else {
      cout << l[1] << " " << r[1] << endl;
      l[1]++;
      r[1]--;
    }
  }
}
