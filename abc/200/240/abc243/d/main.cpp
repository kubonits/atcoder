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
  ll x;
  string s;
  cin >> n >> x >> s;
  vector<int> v(n), st;
  for (int i = 0; i < n; i++) {
    v[i] = 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'U') {
      st.push_back(i);
    } else if (!st.empty()) {
      v[i] = 0;
      v[st.back()] = 0;
      st.pop_back();
    }
  }
  for (int i = 0; i < n; i++) {
    if (v[i]) {
      if (s[i] == 'U') {
        x /= 2LL;
      } else if (s[i] == 'R') {
        x *= 2LL;
        x++;
      } else {
        x *= 2LL;
      }
    }
  }
  cout << x << endl;
}
