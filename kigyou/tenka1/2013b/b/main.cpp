#include <iostream>
#include <stack>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;
int main() {
  ll n, m, q, l, size = 0LL;
  string s;
  stack<pair<ll, ll> > st;
  cin >> q >> l;
  for (int i = 0; i < q; i++) {
    cin >> s;
    if (s == "Top" && size != 0) {
      cout << st.top().first << endl;
    } else if (s == "Top") {
      cout << "EMPTY" << endl;
      return 0;
    } else if (s == "Size") {
      cout << size << endl;
    } else if (s == "Push") {
      cin >> n >> m;
      if (size > l - n) {
        cout << "FULL" << endl;
        return 0;
      } else {
        st.push({m, n});
        size += n;
      }
    } else if (s == "Pop") {
      cin >> n;
      if (n > size) {
        cout << "EMPTY" << endl;
        return 0;
      }
      size -= n;
      int flag = 1;
      pair<ll, ll> p;
      while (flag && !st.empty()) {
        p = st.top();
        st.pop();
        if (p.second > n) {
          p.second -= n;
          flag = 0;
        } else {
          n -= p.second;
        }
      }
      st.push(p);
    }
  }
  cout << "SAFE" << endl;
}