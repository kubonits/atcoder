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
  int n, x, a;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a;
    x -= a;
    if (i % 2) {
      x++;
    }
  }
  cout << (x >= 0 ? "Yes" : "No") << endl;
}