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
  int n, x;
  cin >> n;
  int mini = 0, maxi = 0;
  vector<int> a(n), v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  x = (a[0] ? 1 : -1);
  for (int i = 1; i < n; i++) {
    if (a[i] && x > 0) {
      x++;
    } else if (a[i]) {
      v.push_back(x);
      x = 1;
    } else if (x < 0) {
      x--;
    } else {
      v.push_back(x);
      x = -1;
    }
  }
  v.push_back(x);
  x = 0;
  for (int i = 0; i < v.size(); i++) {
    x += v[i];
    maxi = max(maxi, x);
    if (x < 0) {
      x = 0;
    }
  }
  x = 0;
  for (int i = 0; i < v.size(); i++) {
    x += v[i];
    mini = min(mini, x);
    if (x > 0) {
      x = 0;
    }
  }
  cout << maxi - mini + 1 << endl;
}
