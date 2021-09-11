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
  vector<int> x(10);
  for (int i = 1; i <= 5; i++) {
    cin >> x[i];
    if (x[i] == 0) {
      n = i;
    }
  }
  cout << n << endl;
}