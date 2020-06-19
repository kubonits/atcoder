#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int> > v(n);
  for (int i = 0; i < n; i++) {
    v[i].resize(n);
    for (int j = 0; j < n; j++) {
      v[i][j] = i * n + j + 1;
    }
  }
  if (n % 2 == 0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  for (int i = 0; i < n / 2; i++) {
    int temp = v[i][i];
    int j = n - 1 - i;
    v[i][i] = v[j][j];
    v[j][j] = temp;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}