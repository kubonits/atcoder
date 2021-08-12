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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a >= c && a <= d || b >= c && b <= d || c >= a && c <= b ||
      d >= a && d <= b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}