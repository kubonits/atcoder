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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  ll n, m;
  cin >> n >> m;
  while (n || m) {
    if (n % 10 + m % 10 >= 10) {
      cout << "Hard" << endl;
      return 0;
    }
    n /= 10;
    m /= 10;
  }
  cout << "Easy" << endl;
}
