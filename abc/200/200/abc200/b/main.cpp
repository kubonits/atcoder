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
  ll n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    if (n % 200LL == 0) {
      n /= 200LL;
    } else {
      n *= 1000LL;
      n += 200LL;
    }
  }
  cout << n << endl;
}
