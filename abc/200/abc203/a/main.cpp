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
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b) {
    cout << c << endl;
  } else if (b == c) {
    cout << a << endl;
  } else if (a == c) {
    cout << b << endl;
  } else {
    cout << 0 << endl;
  }
}