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
  int n, p = 0;
  cin >> n;
  vector<string> s(n);
  string t(n, '.');
  for (int i = 0; i < (n % 3 ? 3 : 0); i++) {
    s[i] = t;
    for (int j = 0; j < 2; j++) {
      s[i][p % (n / 3 * 3) + 1] = '#';
      p++;
    }
    s[i][0] = '#';
    cout << s[i] << endl;
  }
  for (int i = (n % 3 ? 3 : 0); i < n - (n % 3 == 2 ? 3 : 0); i++) {
    s[i] = t;
    for (int j = 0; j < 3; j++) {
      s[i][p % (n / 3 * 3) + (n % 3 ? 1 : 0)] = '#';
      p++;
    }
    cout << s[i] << endl;
  }
  for (int i = (n % 3 == 2 ? n - 3 : n); i < n; i++) {
    s[i] = t;
    for (int j = 0; j < 2; j++) {
      s[i][p % (n / 3 * 3) + 1] = '#';
      p++;
    }
    s[i][n - 1] = '#';
    cout << s[i] << endl;
  }
}