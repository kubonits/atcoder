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
  int n;
  string s[50];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < s[i].length(); j++) {
      for (int k = max(0, j - 1); k < min((int)s[i].length(), j + 2); k++) {
        if (s[i][j] == 'X' && s[i - 1][k] == '#') {
          s[i - 1][k] = 'X';
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << s[i] << endl;
  }
}