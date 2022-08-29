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
  ll n, ans = 0LL;
  string s;
  cin >> n >> s;
  vector<int> sum[4];
  for (int i = 0; i < 4; i++) {
    sum[i].resize(n + 1);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      sum[j][i + 1] = sum[j][i];
    }
    if (s[i] == 'A') {
      sum[0][i + 1]++;
    }
    if (s[i] == 'T') {
      sum[1][i + 1]++;
    }
    if (s[i] == 'C') {
      sum[2][i + 1]++;
    }
    if (s[i] == 'G') {
      sum[3][i + 1]++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (sum[0][j] - sum[0][i] == sum[1][j] - sum[1][i] &&
          sum[2][j] - sum[2][i] == sum[3][j] - sum[3][i]) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}