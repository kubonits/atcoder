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
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  set<pair<int, int> > s1, s2;
  for (int i = -2; i <= 2; i++) {
    for (int j = -2; j <= 2; j++) {
      if (abs(i) == 2 && abs(j) == 1 || abs(i) == 1 && abs(j) == 2) {
        s1.insert({x1 + i, y1 + j});
        s2.insert({x2 + i, y2 + j});
      }
    }
  }
  for (auto &&x : s1) {
    if (s2.find(x) != s2.end()) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
