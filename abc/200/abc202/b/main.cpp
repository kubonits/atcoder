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
  string s;
  cin >> s;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] == '6') {
      cout << 9;
    } else if (s[i] == '9') {
      cout << 6;
    } else {
      cout << s[i];
    }
  }
  cout << endl;
}