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
  int n, m;
  cin >> n >> m;
  if (n + m >= 15 && m >= 8) {
    cout << 1 << endl;
  } else if (n + m >= 10 && m >= 3) {
    cout << 2 << endl;
  } else if (n + m >= 3) {
    cout << 3 << endl;
  } else {
    cout << 4 << endl;
  }
}
