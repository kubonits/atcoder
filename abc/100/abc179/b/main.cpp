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
  int n, x, y, cnt = 0, maxi = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if (x == y) {
      cnt++;
    } else {
      cnt = 0;
    }
    maxi = max(maxi, cnt);
  }
  cout << (maxi >= 3 ? "Yes" : "No") << endl;
}