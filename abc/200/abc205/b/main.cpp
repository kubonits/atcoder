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
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (v[i] != i + 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}