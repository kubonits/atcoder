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
  int n, f1 = 0, f2 = 0;
  vector<int> v(5), a(14);
  for (int i = 0; i < 5; i++) {
    cin >> v[i];
    a[v[i]]++;
  }
  for (int i = 1; i <= 13; i++) {
    if (a[i] == 2) {
      f1 = 1;
    }
    if (a[i] == 3) {
      f2 = 1;
    }
  }
  cout << (f1 && f2 ? "Yes" : "No") << endl;
}
