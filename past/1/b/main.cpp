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
  for (int i = 1; i < n; i++) {
    if (v[i] > v[i - 1]) {
      cout << "up " << v[i] - v[i - 1] << endl;
    } else if (v[i] < v[i - 1]) {
      cout << "down " << v[i - 1] - v[i] << endl;
    } else {
      cout << "stay" << endl;
    }
  }
}