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
  double n;
  string s, t;
  cin >> n >> s >> t;
  vector<ll> sum(10);
  ll cnt = 0, win = 0;
  for (int i = 0; i < 10; i++) {
    sum[i] = n;
  }
  for (int i = 0; i < 4; i++) {
    sum[s[i] - '0']--;
    sum[t[i] - '0']--;
  }
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      if (i == j && sum[i] >= 2 || i != j && sum[i] >= 1 && sum[j] >= 1) {
        int x = 0, y = 0;
        for (int k = 1; k < 10; k++) {
          int z = 1;
          for (int l = 0; l < 4; l++) {
            if ((s[l] - '0') == k) {
              z *= 10;
            }
          }
          if (i == k) {
            z *= 10;
          }
          x += z * k;
          z = 1;
          for (int l = 0; l < 4; l++) {
            if ((t[l] - '0') == k) {
              z *= 10;
            }
          }
          if (j == k) {
            z *= 10;
          }
          y += z * k;
        }
        if (x > y) {
          win += (i == j ? sum[i] * (sum[i] - 1) : sum[i] * sum[j]);
        }
        cnt += (i == j ? sum[i] * (sum[i] - 1) : sum[i] * sum[j]);
      }
    }
  }
  cout << fixed << setprecision(15) << (double)win / (double)cnt << endl;
}
