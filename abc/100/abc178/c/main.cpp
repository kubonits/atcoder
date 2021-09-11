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
  int n;
  cin >> n;
  vector<ll> a[4];
  for (int i = 0; i < 4; i++) {
    a[i].resize(n + 1);
    a[i][0] = 0LL;
  }
  a[0][0] = 1LL;
  for (int i = 0; i < n; i++) {
    a[0][i + 1] = a[0][i] * 8 % MOD;
    a[1][i + 1] = (a[0][i] + a[1][i] * 9) % MOD;
    a[2][i + 1] = (a[0][i] + a[2][i] * 9) % MOD;
    a[3][i + 1] = (a[1][i] + a[2][i] + a[3][i] * 10) % MOD;
  }
  cout << a[3][n] % MOD << endl;
}