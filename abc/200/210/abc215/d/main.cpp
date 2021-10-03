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
  int n, m;
  cin >> n >> m;
  vector<int> v(n), a(100001), ans;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i <= m; i++) {
    a[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 2; j <= sqrt(v[i]); j++) {
      if (v[i] % j == 0) {
        while (v[i] % j == 0) {
          v[i] /= j;
        }
        if (a[j] == 1) {
          a[j] = 0;
          for (int k = j * 2; k <= m; k += j) {
            a[k] = 0;
          }
        }
      }
    }
    if (v[i] != 1 && a[v[i]] == 1) {
      for (int j = v[i]; j <= m; j += v[i]) {
        a[j] = 0;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (a[i]) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}