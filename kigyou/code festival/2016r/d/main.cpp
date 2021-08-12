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
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int a[3][3];
  cin >> a[0][0] >> a[0][1] >> a[1][1];
  a[2][0] = a[0][0] + a[0][1] - a[1][1];
  a[1][2] = a[0][0] + a[2][0] - a[1][1];
  a[2][2] = a[0][0] + a[0][1] - a[1][2];
  a[1][0] = a[0][0] + a[2][2] - a[1][2];
  a[0][2] = a[1][1] + a[2][2] - a[0][1];
  a[2][1] = a[0][0] + a[2][2] - a[0][1];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}