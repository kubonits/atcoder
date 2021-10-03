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
  ll a, b, k;
  cin >> a >> b >> k;
  cout << max(a - k, 0LL) << " " << max(0LL, b - max(0LL, k - a)) << endl;
}