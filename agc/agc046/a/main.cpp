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
  cin >> n;
  vector<int> v(n + 10);
  for (int i = 1; i <= 360; i++) {
    if ((n * i) % 360 == 0) {
      cout << i << endl;
      return 0;
    }
  }
}