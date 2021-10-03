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
  int n = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    n += s[i] - '0';
    n %= 9;
  }
  cout << (n == 0 ? "Yes" : "No") << endl;
}