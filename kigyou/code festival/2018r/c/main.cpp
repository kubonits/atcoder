#include <algorithm>
#include <cmath>
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

int n, H, h[10], f[10];

int calc(int x) {
  int res = 0, sum = 0;
  if (x == n) {
    return 1;
  }
  for (int i = 0; i < n; i++) {
    if (f[i] == 0) {
      sum += h[i];
      if (sum <= H) {
        f[i] = 1;
        res += calc(x + 1);
        f[i] = 0;
      }
    }
  }
  return res;
}

int main() {
  cin >> n >> H;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  cout << calc(0) << endl;
}