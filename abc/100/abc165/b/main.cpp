#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  long long n, a = 100LL;
  cin >> n;
  int cnt = 0;
  while (n > a) {
    a += a / 100LL;
    cnt++;
  }
  cout << cnt << endl;
}