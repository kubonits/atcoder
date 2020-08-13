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

int main() {
  int n, a[10001] = {};
  cin >> n;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      for (int k = 1; k <= 100; k++) {
        int x = i * i + j * j + k * k + i * j + j * k + k * i;
        if (x <= n) {
          a[x]++;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << endl;
  }
}