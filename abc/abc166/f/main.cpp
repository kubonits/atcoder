#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
string s[100000];
int main() {
  int n, a, b, c, cnt = 0;
  vector<char> ans;
  cin >> n >> a >> b >> c;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == "AB") {
      if (s[i] == "AB" && a == 0 && b == 0) {
        cout << "No" << endl;
        return 0;
      } else if (s[i] == "AB" && (a > b || a == b && a > 1)) {
        ans.push_back('B');
        a--;
        b++;
      } else if (s[i] == "AB" && a < b) {
        ans.push_back('A');
        a++;
        b--;
      } else if (s[i] == "AB" && i + 1 < n && s[i + 1] == "BC") {
        ans.push_back('B');
        a--;
        b++;
      } else {
        ans.push_back('A');
        a++;
        b--;
      }
    }
    if (s[i] == "BC") {
      if (b == 0 && c == 0) {
        cout << "No" << endl;
        return 0;
      }
      if (b > c || b == c && b > 1) {
        ans.push_back('C');
        c++;
        b--;
      } else if (b < c || i + 1 < n && s[i + 1] == "AB") {
        ans.push_back('B');
        c--;
        b++;
      } else {
        ans.push_back('C');
        c++;
        b--;
      }
    }
    if (s[i] == "AC") {
      if (a == 0 && c == 0) {
        cout << "No" << endl;
        return 0;
      } else if (a < c || a == c && c > 1) {
        ans.push_back('A');
        a++;
        c--;
      } else if (a > c || i + 1 < n && s[i + 1] == "BC") {
        ans.push_back('C');
        c++;
        a--;
      } else {
        ans.push_back('A');
        a++;
        c--;
      }
    }
  }
  cout << "Yes" << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}
