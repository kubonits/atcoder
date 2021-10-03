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
  int same = 1, next = 1;
  string s;
  cin >> s;
  for (int i = 0; i < 3; i++) {
    if (s[i + 1] != s[0]) {
      same = 0;
    }
    int x = s[i] - '0';
    int y = s[i + 1] - '0';
    if (y != (x + 1) % 10) {
      next = 0;
    }
  }
  if (same || next) {
    cout << "Weak" << endl;
  } else {
    cout << "Strong" << endl;
  }
}