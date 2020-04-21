#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int main() {
  int n, k;
  string s[100];
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  sort(s, s + n);
  for (int i = n - 1; i >= 0; i--) {
    cout << s[i];
  }
  cout << endl;
}