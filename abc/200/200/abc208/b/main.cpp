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
  int res = 1;
  for (int i = 2; i <= x; i++) {
    res *= i;
  }
  return res;
}

int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 10; i >= 1; i--) {
    ans += n / calc(i);
    n %= calc(i);
  }
  cout << ans << endl;
}