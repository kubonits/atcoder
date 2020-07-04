#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, k;
  vector<int> v;
  cin >> n >> k;
  for (int i = 2; i <= sqrt(n) && v.size() < k - 1; i++) {
    while (n % i == 0 && v.size() < k - 1) {
      v.push_back(i);
      n /= i;
    }
  }
  if (n != 1) {
    v.push_back(n);
  }
  if (v.size() == k) {
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
  } else {
    cout << -1 << endl;
  }
}