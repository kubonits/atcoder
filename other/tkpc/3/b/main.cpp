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
  int n, a = 0, b = 0;
  string s;
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    a *= 10;
    b *= 10;
    a += s[i] - '0';
    b += s[i] - '0';
    a %= 6;
    b %= 11;
  }
  cout << (a ? "nO" : "yES") << endl;
  cout << (b ? "nO" : "yES") << endl;
}