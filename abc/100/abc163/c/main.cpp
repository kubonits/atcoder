#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int a[200000], sum[200001];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    sum[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    cout << sum[i] << endl;
  }
}