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
  string s;
  set<string> se;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    se.insert(s);
    string t;
    if (s[0] == '!') {
      t = s.substr(1);
    } else {
      t = "!" + s;
    }
    if (se.find(t) != se.end()) {
      cout << (s[0] == '!' ? s.substr(1) : s) << endl;
      return 0;
    }
  }
  cout << "satisfiable" << endl;
}
