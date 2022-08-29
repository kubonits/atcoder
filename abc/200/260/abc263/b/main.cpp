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
  int n, p;
  cin >> n;
  vector<int> a(n);
  a[0] = 0;
  for (int i = 1; i < n; i++) {
    cin >> p;
    a[i] = a[p - 1] + 1;
  }
  cout << a[n - 1] << endl;
}
