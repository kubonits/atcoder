#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
int main() {
  int n, a[100000], b[100000], mini = 0;
  vector<int> v;
  map<int, int> m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < v.size(); i++) {
    m.insert({v[i], i});
  }
  for (int i = 0; i < n; i++) {
    printf("%d\n", m[a[i]]);
  }
}