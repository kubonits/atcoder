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
  char s[3], t[3];
  int cnt = 0;
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 3; i++) {
    cin >> t[i];
    if (s[i] == t[i]) {
      cnt++;
    }
  }
  cout << (cnt == 1 ? "No" : "Yes") << endl;
}
