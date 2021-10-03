#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  string s;
  set<char> se;
  se.insert('B');
  se.insert('R');
  se.insert('H');
  se.insert('G');
  for(int i=0;i<3;i++){
    cin>>s;
    se.erase(s[1]);
  }
  cout<<"A"<<*se.begin()<<"C"<<endl;
}