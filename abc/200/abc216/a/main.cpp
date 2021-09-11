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
  int n = 0, m = 0, flag = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '.') {
      flag = 1;
    } else if (flag == 0) {
      n *= 10;
      n += s[i] - '0';
    } else {
      m = s[i] - '0';
    }
  }
  cout << n;
  if (m <= 2) {
    cout << "-" << endl;
  } else if (m >= 7) {
    cout << "+" << endl;
  } else {
    cout << endl;
  }
}