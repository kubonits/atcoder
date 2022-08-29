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
  int n, l;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    int x = 2 * pow(3, l - 1) + i;
    string s = "";
    for (int j = 0; j < l; j++) {
      if (x % 3 == 0) {
        s += "0";
      } else if (x % 3 == 1) {
        s += "1";
      } else {
        s += "2";
      }
      x /= 3;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    for (int j = 0; j < l; j++) {
      if (s[j] == '0') {
        cout << "1";
      } else if (s[j] == '1') {
        cout << "2";
      } else {
        cout << "0";
      }
    }
    cout << endl;
    for (int j = 0; j < l; j++) {
      if (s[j] == '0') {
        cout << "2";
      } else if (s[j] == '1') {
        cout << "0";
      } else {
        cout << "1";
      }
    }
    cout << endl;
  }
}
