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
  ll a, b, c;
  cin >> a >> b >> c;
  if (c % 2 == 0) {
    a = a * a;
    b = b * b;
  }
  if (a == b) {
    cout << "=" << endl;
  } else {
    cout << (a > b ? ">" : "<") << endl;
  }
}