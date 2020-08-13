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
  if (n % 400 == 0 || n % 4 == 0 && n % 100 != 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}