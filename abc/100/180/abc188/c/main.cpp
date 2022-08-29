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
  int n, a;
  pair<int, int> b = {0, 0}, c = {0, 0};
  cin >> n;
  for (int i = 0; i < (1 << (n - 1)); i++) {
    cin >> a;
    b = max(b, {a, i});
  }
  for (int i = 0; i < (1 << (n - 1)); i++) {
    cin >> a;
    c = max(c, {a, i + (1 << (n - 1))});
  }
  cout << min(b, c).second + 1 << endl;
}
