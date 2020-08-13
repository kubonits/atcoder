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
  int n, sum = 0, l = 0, ans = 0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
    while (sum > n) {
      sum -= v[l];
      l++;
    }
    if (sum == n) {
      ans++;
    }
  }
  cout << ans << endl;
}