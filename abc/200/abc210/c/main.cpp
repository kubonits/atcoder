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
  int n, k, ans = 0;
  map<int, int> m;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    m[v[i]]++;
    if (i >= k) {
      m[v[i - k]]--;
      if (m[v[i - k]] == 0) {
        m.erase(v[i - k]);
      }
    }
    ans = max(ans, (int)m.size());
  }
  cout << ans << endl;
}