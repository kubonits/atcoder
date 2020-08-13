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

int main() {
  int n, ans = 1;
  cin >> n;
  vector<int> a(n), b(n), x;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= sqrt(a[0]); i++) {
    if (a[0] % i == 0) {
      x.push_back(i);
      x.push_back(a[0] / i);
    }
  }
  for (int i = 1; i <= sqrt(b[0]); i++) {
    if (b[0] % i == 0) {
      x.push_back(i);
      x.push_back(b[0] / i);
    }
  }
  for (int i = 0; i < x.size(); i++) {
    int flag = 1;
    for (int j = 0; j < n; j++) {
      if (a[j] % x[i] && b[j] % x[i]) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      ans = max(ans, x[i]);
    }
  }
  cout << ans << endl;
}