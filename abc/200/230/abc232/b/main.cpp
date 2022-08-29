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
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.length(); i++) {
    if ((s[i] - t[i] + 26) % 26 != (s[0] - t[0] + 26) % 26) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
