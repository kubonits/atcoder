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
  string s;
  set<char> se;
  int f1 = 0, f2 = 0;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      f1 = 1;
    } else {
      f2 = 1;
    }
    if (se.find(s[i]) == se.end()) {
      se.insert(s[i]);
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << (f1 && f2 ? "Yes" : "No") << endl;
}
