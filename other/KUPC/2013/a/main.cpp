#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, q, y;
  string s, ans = "kogakubu10gokan";
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> y >> s;
    if (y <= q) {
      ans = s;
    }
  }
  cout << ans << endl;
}