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
  vector<int> a, b;
  string s;
  cin >> s;
  for (int i = 0; i < 4; i++) {
    a.push_back(s[i] - '0');
  }
  for (int i = 5; i < 7; i++) {
    b.push_back(s[i] - '0');
  }
  for (int i = 8; i < 10; i++) {
    b.push_back(s[i] - '0');
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < 4; i++) {
    if (a[i] != b[i]) {
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
}