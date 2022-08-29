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

int main() {
  int n, dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1}, d = 0, x = 0, y = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'S') {
      x += dx[d];
      y += dy[d];
    } else {
      d++;
      d %= 4;
    }
  }
  cout << x << " " << y << endl;
}
