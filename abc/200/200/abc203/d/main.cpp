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
  int n, k, left, right, mid, flag;
  cin >> n >> k;
  vector<vector<int> > a(n, vector<int>(n)), sum(n + 1, vector<int>(n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  left = 0;
  right = 1000000000;
  while (left <= right) {
    mid = (left + right) / 2;
    flag = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        sum[i][j] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] > mid) {
          sum[i + 1][j + 1]++;
          if (i + k < n) {
            sum[i + k + 1][j + 1]--;
          }
          if (j + k < n) {
            sum[i + 1][j + k + 1]--;
          }
          if (i + k < n && j + k < n) {
            sum[i + k + 1][j + k + 1]++;
          }
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < n; j++) {
        sum[i][j + 1] += sum[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= n; j++) {
        sum[i + 1][j] += sum[i][j];
      }
    }
    for (int i = k; i <= n; i++) {
      for (int j = k; j <= n; j++) {
        if (sum[i][j] <= (k * k) / 2) {
          flag = 1;
        }
      }
    }
    if (!flag) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << left << endl;
}