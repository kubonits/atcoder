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
  string s[3], t;
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
  }
  cin >> t;
  for (int i = 0; i < t.length(); i++) {
    if (t[i] == '1') {
      cout << s[0];
    } else if (t[i] == '2') {
      cout << s[1];
    } else {
      cout << s[2];
    }
  }
  cout << endl;
}
