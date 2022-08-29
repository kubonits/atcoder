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
  int a, b, c;
  cin >> a >> b >> c;
  while (1) {
    if (c % 2) {
      if (!b--) {
        cout << "Takahashi" << endl;
        return 0;
      }
    } else {
      if (!a--) {
        cout << "Aoki" << endl;
        return 0;
      }
    }
    c^=1;
  }
}
