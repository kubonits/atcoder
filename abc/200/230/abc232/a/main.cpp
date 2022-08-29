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
  ll a = 0, b = 0, flag = 0;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'x') {
      flag = 1;
    } else if (flag == 0) {
      a *= 10;
      a += s[i] - '0';
    } else {
      b *= 10;
      b += s[i] - '0';
    }
  }
  cout << a * b << endl;
}
