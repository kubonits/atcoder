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
  int a[3] = {};
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    a[s[i] - 'a']++;
  }
  if (a[0] > a[1] && a[0] > a[2]) {
    cout << "a" << endl;
  } else if (a[1] > a[2]) {
    cout << "b" << endl;
  } else {
    cout << "c" << endl;
  }
}