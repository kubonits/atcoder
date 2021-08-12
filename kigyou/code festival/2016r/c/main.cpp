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
  int n;
  cin >> n;
  vector<int> a(1 << (n + 1) + 1);
  for (int i = 0; i < (1 << n); i++) {
    cin >> a[(1 << n) + i];
  }
  for (int i = (1 << n) - 1; i >= 1; i--) {
    a[i] = (a[2 * i] == a[2 * i + 1] ? a[2 * i] : abs(a[2 * i] - a[2 * i + 1]));
  }
  cout << a[1] << endl;
}