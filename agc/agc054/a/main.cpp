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
  string s;
  cin >> n >> s;
  if (s[0] != s[n - 1]) {
    cout << 1 << endl;
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != s[0] && s[i + 1] != s[0]) {
      cout << 2 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
