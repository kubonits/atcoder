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
  string s;
  cin >> s;
  if (s[0] == s[1] && s[0] == s[2]) {
    cout << 1 << endl;
    return 0;
  }
  if (s[0] == s[1] || s[1] == s[2] || s[2] == s[0]) {
    cout << 3 << endl;
    return 0;
  }
  cout << 6 << endl;
}
