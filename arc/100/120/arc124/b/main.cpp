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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    int x = a[i] ^ b[0];
    map<int, int> m;
    int flag = 1;
    for (int j = 0; j < n; j++) {
      m[b[j]]++;
    }
    for (int j = 0; j < n; j++) {
      if (m.find(x ^ a[j]) == m.end() || m[x ^ a[j]] == 0) {
        flag = 0;
        break;
      } else {
        m[x ^ a[j]]--;
      }
    }
    if (flag) {
      s.insert(x);
    }
  }
  cout << s.size() << endl;
  for (auto &&ans : s) {
    cout << ans << endl;
  }
}
