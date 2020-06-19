#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int n, a, ans = 0;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (!i || v.back() != a) {
      v.push_back(a);
    }
  }
  for (int i = 0; i < v.size(); i++) {
    if (!i || i == v.size() - 1 || (v[i] > v[i - 1] && v[i] > v[i + 1]) ||
        (v[i] < v[i - 1] && v[i] < v[i + 1])) {
      ans++;
    }
  }
  if (v.size() == 1) {
    ans = 0;
  }
  cout << ans << endl;
}