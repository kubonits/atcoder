#include <algorithm>
#include <cmath>
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

int main() {
  string s, t;
  int a, b;
  cin >> s >> t;
  if (s[0] == 'B') {
    a = 1 - (s[1] - '0');
  } else {
    a = s[0] - '0';
  }
  if (t[0] == 'B') {
    b = 1 - (t[1] - '0');
  } else {
    b = t[0] - '0';
  }
  cout << abs(a - b) << endl;
}