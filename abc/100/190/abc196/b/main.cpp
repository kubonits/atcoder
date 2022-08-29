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
  string n;
  cin >> n;
  for (int i = 0; i < n.length(); i++) {
    if (n[i] != '.') {
      cout << n[i];
    } else {
      cout << endl;
      return 0;
    }
  }
  cout << endl;
}
