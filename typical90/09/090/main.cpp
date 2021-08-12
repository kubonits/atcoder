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
#define MOD 998244353
using namespace std;
typedef long long ll;
#include <cstring>

ll dfs(ll n, ll l, vector<int> v) {
  ll ans = 0;
  if (v.size() == n) {
    for (int k = 1; k <= n; k++) {
      for (int i = 0; i + k - 1 < n; i++) {
        int x = 10;
        for (int j = 0; j < k; j++) {
          x = min(x, v[i + j]);
        }
        if (x * k > l) {
          return 0LL;
        }
      }
    }
    return 1LL;
  }
  for (int i = 0; i <= 6; i++) {
    v.push_back(i);
    ans = (ans + dfs(n, l, v)) % MOD;
    v.pop_back();
  }
  return ans % MOD;
}

int main() {
  ll n, k;
  cin >> n >> k;
  if (k == 1) {
    ll mat[4] = {1, 1, 1, 0}, ans_mat[4] = {1, 0, 0, 1}, tmp_mat[4];
    for (int i = 0; i < 40; i++) {
      if (n & (1LL << i)) {
        tmp_mat[0] =
            (mat[0] * ans_mat[0] % MOD + mat[1] * ans_mat[2] % MOD) % MOD;
        tmp_mat[1] =
            (mat[0] * ans_mat[1] % MOD + mat[1] * ans_mat[3] % MOD) % MOD;
        tmp_mat[2] =
            (mat[2] * ans_mat[0] % MOD + mat[3] * ans_mat[2] % MOD) % MOD;
        tmp_mat[3] =
            (mat[2] * ans_mat[1] % MOD + mat[3] * ans_mat[3] % MOD) % MOD;
        for (int j = 0; j < 4; j++) {
          ans_mat[j] = tmp_mat[j];
        }
      }
      tmp_mat[0] = (mat[0] * mat[0] % MOD + mat[1] * mat[2] % MOD) % MOD;
      tmp_mat[1] = (mat[0] * mat[1] % MOD + mat[1] * mat[3] % MOD) % MOD;
      tmp_mat[2] = (mat[2] * mat[0] % MOD + mat[3] * mat[2] % MOD) % MOD;
      tmp_mat[3] = (mat[2] * mat[1] % MOD + mat[3] * mat[3] % MOD) % MOD;
      for (int j = 0; j < 4; j++) {
        mat[j] = tmp_mat[j];
      }
    }
    cout << (ans_mat[0] + ans_mat[1]) % MOD << endl;
    return 0;
  }
  if (n <= 6 && k <= 6) {
    vector<int> v;
    cout << dfs(n, k, v) << endl;
    for (int i = 1; i <= 6; i++) {
      for (int j = 1; j <= 6; j++) {
        cout << dfs(i, j, v) << "\t";
      }
      cout << endl;
    }
  }
}