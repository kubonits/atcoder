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
  int n, ans = 0;
  cin >> n;
  vector<int> a(n), b(n), f(1001);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i <= 1000; i++) {
    f[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a[i]; j++) {
      f[j] = 0;
    }
    for (int j = b[i] + 1; j <= 1000; j++) {
      f[j] = 0;
    }
  }
  for (int i = 1; i <= 1000; i++) {
    ans += f[i];
  }
  cout << ans << endl;
}
