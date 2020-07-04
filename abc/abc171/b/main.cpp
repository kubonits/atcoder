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
  int n, k, ans = 0;
  cin >> n >> k;
  vector<int> v(n + 10);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.begin() + n);
  for (int i = 0; i < k; i++) {
    ans += v[i];
  }
  cout << ans << endl;
}