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
  if (n < 40) {
    cout << 40 - n << endl;
  } else if (n < 70) {
    cout << 70 - n << endl;
  } else if (n < 90) {
    cout << 90 - n << endl;
  } else {
    cout << "expert" << endl;
  }
}
