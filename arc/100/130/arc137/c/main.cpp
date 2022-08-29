#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int v[10][10][10];

int calc(int x, int y, int z, int a) {
  // cout << x << " " << y << " " << z << endl;
  if (x == 0 && y == 1 && z == 2) {
    return -a;
  }
  if (v[x][y][z]) {
    return v[x][y][z] * a;
  }
  for (int i = 0; i < x; i++) {
    if (calc(i, x, y, -a) == a) {
      v[x][y][z] = a;
      return a;
    }
  }
  for (int i = x + 1; i < y; i++) {
    if (calc(x, i, y, -a) == a) {
      v[x][y][z] = a;
      return a;
    }
  }
  for (int i = y + 1; i < z; i++) {
    if (calc(x, y, i, -a) == a) {
      v[x][y][z] = a;
      return a;
    }
  }
  v[x][y][z] = -a;
  return -a;
}

int main() {
  int n;
  // for (int k = 0; k <= 10; k++) {
  //   for (int j = 0; j < k; j++) {
  //     for (int i = 0; i < j; i++) {
  //       if (calc(i, j, k, 1) == -1) {
  //         cout << i << " " << j << " " << k << endl;
  //       }
  //     }
  //   }
  // }
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[n - 1] - a[n - 2] == 1 && (a[n - 1] + n) % 2 == 1) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }
}
