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
  int n, h, w;
  cin >> h >> w >> n;
  vector<int> a(n), b(n);
  set<int> sa, sb;
  map<int, int> ma, mb;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    sa.insert(a[i]);
    sb.insert(b[i]);
  }
  int cnt = 0;
  for (auto &&x : sa) {
    ma[x] = cnt;
    cnt++;
  }
  h = cnt;
  cnt = 0;
  for (auto &&x : sb) {
    mb[x] = cnt;
    cnt++;
  }
  w = cnt;
  for (int i = 0; i < n; i++) {
    cout << ma[a[i]] + 1 << " " << mb[b[i]] + 1 << endl;
  }
}