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
  int n, f = 0;
  cin >> n;
  vector<int> ans(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (f == 0 && a[i] > a[i + 1]) {
      ans[i] = 1;
      f = 1;
    } else if (f == 1 && a[i] < a[i + 1]) {
      ans[i] = 1;
      f = 0;
    }
  }
  if (f == 1) {
    ans[n - 1] = 1;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
