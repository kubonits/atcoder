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
  int n, x = 7;
  set<int> s;
  cin >> n;
  for (int i = 1; i <= 1000000; i++) {
    if (x % n == 0) {
      cout << i << endl;
      return 0;
    }
    x *= 10;
    x += 7;
    x %= n;
  }
  cout << -1 << endl;
}