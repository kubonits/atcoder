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
  cin >> n;
  for (int i = 0; i < (1 << n); i++) {
    int sum = 0;
    string s = "";
    for (int j = 0; j < n; j++) {
      if (i & (1 << (n - 1 - j))) {
        s += ")";
        sum--;
      } else {
        s += "(";
        sum++;
      }
      if (sum < 0) {
        break;
      }
    }
    if (sum == 0) {
      cout << s << endl;
    }
  }
}