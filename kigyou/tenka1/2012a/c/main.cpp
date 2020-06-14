#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, m, a, b;
  string s;
  stack<int> st;
  set<int> se;
  cin >> n >> m;
  vector<pair<int, int> > v;
  vector<int> flag(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }
  cin >> s;
  while (1) {
    if (s.substr(s.length() - 3) == "\"ww") {
      st.push(1);
      s.pop_back();
      s.pop_back();
      s.pop_back();
    } else if (s.back() == '\"') {
      st.push(0);
      s.pop_back();
    } else if (s.back() == 'w') {
      st.push(1);
      s.pop_back();
      break;
    } else {
      st.push(0);
      break;
    }
  }
  a = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      a *= 10;
      a += s[i] - '0';
    }
  }
  se.insert(a);
  while (!st.empty()) {
    int x = st.top();
    st.pop();
    for (int i = 1; i <= n; i++) {
      flag[i] = 0;
    }
    if (x) {
      for (int i = 0; i < m; i++) {
        if (se.find(v[i].second) != se.end()) {
          flag[v[i].first] = 1;
        }
      }
      se.clear();
      for (int i = 1; i <= n; i++) {
        if (flag[i]) {
          se.insert(i);
        }
      }
    } else {
      for (int i = 0; i < m; i++) {
        if (se.find(v[i].second) != se.end()) {
          flag[v[i].first]++;
        }
      }
      for (int i = 1; i <= n; i++) {
        if (flag[i] < se.size()) {
          flag[i] = 1;
        } else {
          flag[i] = 0;
        }
      }
      se.clear();
      for (int i = 1; i <= n; i++) {
        if (flag[i]) {
          se.insert(i);
        }
      }
    }
  }
  cout << se.size() << endl;
}