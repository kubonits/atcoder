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
  int x = 1000;
  while (x--) {
    int n;
    n = rand() % 5 + 1;
    set<int> s;
    vector<int> a(n), sum(n + 1), sum2(n + 1);
    int mini = n + 1, maxi = -n - 1;
    for (int i = 0; i < n; i++) {
      a[i] = rand() % 2;
      sum[i + 1] = sum[i] + a[i];
      sum2[i + 1] = sum2[i] + (a[i] ? 1 : -1);
      maxi = max(maxi, sum2[i + 1]);
      mini = min(mini, sum2[i + 1]);
    }
    s.insert(sum[n]);
    for (int k = 1; k <= n; k++) {
      for (int i = 0; i + k <= n; i++) {
        s.insert(sum[i] + (k - (sum[i + k] - sum[i])) + sum[n] - sum[i + k]);
      }
    }

    if (s.size() != maxi - mini + 2) {
      cout << n << endl;
      for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
      }
      cout << endl;
      for (int i = 0; i < n; i++) {
        cout << sum2[i + 1] << " ";
      }
      cout << endl;
      cout << "s.size() = " << s.size() << " maxi = " << maxi
           << " mini = " << mini << endl;
      return 0;
    }
  }
}
