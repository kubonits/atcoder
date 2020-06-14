#include <algorithm>
#include <cmath>
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
  ll a, b, v, w, t;
  cin >> a >> v >> b >> w >> t;
  if (abs(a - b) <= t * (v - w)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}