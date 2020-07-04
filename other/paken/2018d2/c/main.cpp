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

int main() {
  int n, flag, p;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i <= n; i++) {
    flag = 1;
    for (int j = 0; j < i; j++) {
      p = 0;
      for (int k = j; k < n; k += i) {
        if (v[k] && p && v[k] != p) {
          flag = 0;
        } else if (v[k] && !p) {
          p = v[k];
        }
      }
    }
    if (flag) {
      cout << i << endl;
      return 0;
    }
  }
}