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
  int a[6];
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  sort(a, a + 6);
  cout << a[3] << endl;
}