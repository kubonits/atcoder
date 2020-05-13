#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
  int n;
  string s, t;
  cin >> s >> t;
  if (s == t.substr(0, s.length())) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}