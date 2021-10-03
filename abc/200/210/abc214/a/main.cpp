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
  if (n < 126) {
    cout << 4 << endl;
  } else if (n < 212) {
    cout << 6 << endl;
  } else {
    cout << 8 << endl;
  }
}