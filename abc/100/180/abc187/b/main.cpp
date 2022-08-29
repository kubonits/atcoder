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
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    for (int j = 0; j < i; j++) {
      if (x[i] != x[j] && (abs((y[i] - y[j]) / (x[i] - x[j])) < 1) ||
          (abs((y[i] - y[j]) / (x[i] - x[j])) == 1 &&
           abs((y[i] - y[j]) % (x[i] - x[j])) == 0)) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
