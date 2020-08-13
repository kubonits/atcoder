#include <algorithm>
#include <cmath>
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

int main() {
  int n, a[100], ans, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    ans = 1;
    x = a[i];
    while (x != i) {
      x = a[x];
      ans++;
    }
    cout << ans << " ";
  }
  cout << endl;
}