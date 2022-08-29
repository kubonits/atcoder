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
  int n;
  cin >> n;
  string s;
  vector<ll> t(n + 1), f(n + 1);
  t[0] = f[0] = 1LL;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == "AND") {
      t[i + 1] = t[i];
      f[i + 1] = t[i] + 2LL * f[i];
    } else {
      t[i + 1] = 2LL * t[i] + f[i];
      f[i + 1] = f[i];
    }
  }
  cout << t[n] << endl;
}
