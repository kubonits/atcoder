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
  string s, t1 = "oxx", t2 = "xxo", t3 = "xox";
  cin >> s;
  int flag = 1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != t1[i % 3]) {
      flag = 0;
    }
  }
  if (flag) {
    cout << "Yes" << endl;
    return 0;
  }
  flag = 1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != t2[i % 3]) {
      flag = 0;
    }
  }
  if (flag) {
    cout << "Yes" << endl;
    return 0;
  }
  flag = 1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != t3[i % 3]) {
      flag = 0;
    }
  }
  if (flag) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
