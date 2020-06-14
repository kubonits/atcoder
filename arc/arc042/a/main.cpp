#include <iostream>
#include <stack>
using namespace std;
int a[100001];
int main() {
  int n, m, b;
  stack<int> s;
  cin >> n >> m;
  for (int i = n; i >= 1; i--) {
    s.push(i);
  }
  for (int i = 0; i < m; i++) {
    cin >> b;
    s.push(b);
  }
  while (!s.empty()) {
    if (a[s.top()] == 0) {
      a[s.top()] = 1;
      cout << s.top() << endl;
    }
    s.pop();
  }
}