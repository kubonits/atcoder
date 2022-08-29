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

int calc(int x) {
  string s, t;
  s = to_string(x);
  sort(s.begin(), s.end());
  t = s;
  reverse(s.begin(), s.end());
  return stoi(s) - stoi(t);
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    n = calc(n);
  }
  cout << n << endl;
}
