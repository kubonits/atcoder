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
  int n, ans;
  map<int, int> ma, mb;
  cin >> n;
  ans = n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    mb[b[i]]++;
  }
  for (int i = 0; i < n; i++) {
    ma[a[i]]++;
    ans = min(ans, mb[a[i]] / ma[a[i]]);
    cout << ans << endl;
  }
}