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
  int n;
  ll sum = 0LL, ans = 0LL, ab;
  cin >> n;
  vector<ll> v(n + 10);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (i > 1) {
      sum ^= v[i];
    }
  }
  ab = (v[0] + v[1] - sum) / 2;
  if (ab & sum) {
    cout << -1 << endl;
  }
  cout << -1 << endl;
}