#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n;
  string s;
  stack<string> st;
  cin >> n;
  while (n--) {
    cin >> s;
    if (s == "READ") {
      cout << st.top() << endl;
      st.pop();
    } else {
      st.push(s);
    }
  }
}
