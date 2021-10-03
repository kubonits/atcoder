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
  cin >>n>> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '1') {
      cout << (i % 2 == 0 ? "Takahashi" : "Aoki") << endl;
      return 0;
    }
  }
}