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
  string s, t;
  cin >> s >> t;
  if (s == t) {
    cout << "Yes" << endl;
    return 0;
  }
  for (int i = 0; i < s.length() - 1; i++) {
    char tmp;
    tmp = s[i];
    s[i] = s[i + 1];
    s[i + 1] = tmp;
    if (s == t) {
      cout << "Yes" << endl;
      return 0;
    }
    tmp = s[i];
    s[i] = s[i + 1];
    s[i + 1] = tmp;
  }
  cout << "No" << endl;
}
