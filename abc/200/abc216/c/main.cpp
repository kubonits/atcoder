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
  ll n;
  int flag = 0;
  cin >> n;
  for (int i = 60; i >= 0; i--) {
    if (flag) {
      cout << "B";
    }
    if (n & (1LL << i)) {
      flag = 1;
      cout << "A";
    }
  }
  cout << endl;
}