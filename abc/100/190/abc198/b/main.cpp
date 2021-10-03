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
  int flag;
  string s;
  cin >> s;
  for (int i = 0; i < 11; i++) {
    flag = 1;
    for (int j = 0; j < s.length(); j++) {
      if (s[j] != s[s.length() - j - 1]) {
        flag = 0;
      }
    }
    if (flag) {
      cout << "Yes" << endl;
      return 0;
    }
    s = "0" + s;
  }
  cout << "No" << endl;
}
