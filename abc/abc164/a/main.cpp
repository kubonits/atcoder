#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define MOD 1000000007
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (m >= n) {
    cout << "unsafe" << endl;
  } else {
    cout << "safe" << endl;
  }
}
