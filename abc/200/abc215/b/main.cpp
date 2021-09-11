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
  ll n;
  cin >> n;
  for (int i = 59; i >= 0; i--) {
    if (n & (1LL << i)) {
      cout << i << endl;
      return 0;
    }
  }
}