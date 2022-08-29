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
  int x, y, ax = 0, ay = 0;
  for (int i = 0; i < 3; i++) {
    cin >> x >> y;
    ax ^= x;
    ay ^= y;
  }
  cout << ax << " " << ay << endl;
}
