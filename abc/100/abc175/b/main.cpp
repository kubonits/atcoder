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
  int n, l[100], ans = 0, maxi;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        maxi = max(l[i], l[j]);
        maxi = max(maxi, l[k]);
        if (maxi < l[i] + l[j] + l[k] - maxi && l[i] != l[j] && l[j] != l[k] &&
            l[i] != l[k]) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}