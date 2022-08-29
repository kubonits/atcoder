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
  int n, k, left, right, ans = 0;
  string s;
  cin >> s >> k;
  n = s.length();
  vector<int> sum(n + 1);
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + (s[i] == '.' ? 1 : 0);
  }
  left = right = 0;
  while (left <= n && right <= n) {
    if (sum[right] - sum[left] <= k) {
      ans = max(ans, right - left);
      right++;
    } else {
      left++;
    }
  }
  cout << ans << endl;
}
