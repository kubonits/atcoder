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

int main() {
  int n, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    cout << a;
    if (i != n - 1) {
      cout << ",";
    }
  }
  cout << endl;
}