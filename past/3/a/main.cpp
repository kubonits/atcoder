#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int n;
  string s, t;
  cin >> s >> t;
  if (s == t) {
    cout << "same" << endl;
    return 0;
  }
  for (int i = 0; i < 3; i++) {
    if (abs(s[i] - t[i]) != 0 && abs(s[i] - t[i]) != 32) {
      cout << "different" << endl;
      return 0;
    }
  }
  cout << "case-insensitive" << endl;
}