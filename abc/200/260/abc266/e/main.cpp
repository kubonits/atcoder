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
  int n;
  cin >> n;
  vector<double> dp(101);
  dp[0] = 0.0;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 6; j++) {
      dp[i] += max(dp[i - 1], (double)j) / 6.0;
    }
  }
  cout << fixed << setprecision(10) << dp[n] << endl;
}
