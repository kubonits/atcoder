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
  int n, a, ans = 0;
  set<int> s;
  cin >> n;
  for (int i = 1; i < 1000; i++) {
    for (int j = 1; 4 * i * j + 3 * i + 3 * j <= 1000; j++) {
      s.insert(4 * i * j + 3 * i + 3 * j);
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (s.find(a) == s.end()) {
      ans++;
    }
  }
  cout << ans << endl;
}
