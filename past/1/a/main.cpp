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
  int ans = 0;
  string s;
  cin >> s;
  for (int i = 0; i < 3; i++) {
    if (!(s[i] >= '0' && s[i] <= '9')) {
      cout << "error" << endl;
      return 0;
    } else {
      ans *= 10;
      ans += s[i] - '0';
    }
  }
  cout << ans * 2 << endl;
}